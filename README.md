# Algorithm
**시간/공간 복잡도**
시간 복잡도 : 입력의 크기와 문제를 해결하는데 걸리는 시간의 상관관계
빅오표기법 : 주어진 식을 값이 가장 큰 대표항만 남겨서 나타내는 방법
O(1) < O(lgN) < O(N) < O(NlgN) < O(N^2) < O(2^n) < O(N!)

공간복잡도 : 입력의 크기와 문제를 해결하는데 필요한 공간의 상관관계
(512MB = 1.2억개의 int자료형을 사용 가능)

**정수/실수 자료형**
정수 자료형
short(2byte) < int(4byte) < long long (8byte)
short~int : sign(1) + fraction (~)
실수 자료형
float(4byte) < double(8byte)
float : sign(1) + exponent(8) + fraction (23)
double : sign(1) + exponent(11) + fraction (52)
1.실수의 저장/연산 과정에서 반드시 오차가 발생할 수 밖에 없다. (float 대신, double 사용)
2진법에서 유한소수 : 분모의 소인수가 2로만 이루어 진 수
2.double에 long long 범위의 정수를 함부로 담으면 안된다.
3.실수를 비교할 때는 등호를 사용하면 안된다.
(허용 오차 : epsilon = 1e-9 를 포함하여 비교한다)

**STL과 함수 인자**
함수 인자에 넣으면 복사 : STL(vector), struction

ex 1.
bool cmp1(vector<int> v1, vector<int> v2, int idx){
    return v1[idx] > v2[idx];
}
시간 복잡도 : O(N) <vector를 복사하는 시간이 있으므로>

ex 2.
bool cmp2(vector<int>& v1, vector<int>& v2, int idx){
    return v1[idx] > v2[idx];
}
시간 복잡도 : O(1)

GCC header : <bits/stdc++.h>

**표준 입출력**
getline(cin, str); <공백 포함 문자열 받기>
ios::sync_with_stdio(0); <C/C++ 동기화 스트림 끊기>
cin.tie(0); <cout 버퍼를 비우지 않음>
※endl 쓰지 말기 <출력 버퍼를 비움>※

**배열**
메모리 상에 원소를 연속하게 배치한 자료구조
1. O(1)에 k번째 원소를 확인/변경 가능 <k번 뒤로 가면 확인 가능>
2. 추가적으로 소모되는 메모리의 양(=overhead)가 거의 없음
3. Cache hit rate가 높음
4. 메모리 상에 연속한 구간을 잡아야 해서 할당에 제약이 걸림

임의의 위치에 있는 원소를 확인/변경, O(1)
끝의 원소를 추가/제거 : O(1)
임의의 위치에 원소를 추가/제거, O(N) <평균적으로 밀어(땡겨)야 하는 개수 : N/2>

fill : fill(arr, arr+arr_size, 0);

**STL vector**
vector<int> v1(3, 5); // {5, 5, 5}
cout << v1.size(); // 3  ※size 함수는 unsigned※
v1.push_back(7); // {5, 5, 5, 7}

vector<int> v2(2); // {0, 0}
v2.insert(v2.begin()+1, 3); // {0, 3, 0}

vector<int> v3 = {1, 2, 3, 4}; // {1, 2, 3, 4}
v3.erase(v3.begin()+2); // {1, 2, 4}

vector<int> v4; // {}
v4 = v3; // {1, 2, 4}
cout << v4[0] << v4[1]; // 12
v4.pop_back(); // {1}
v4.clear(); // {}

range-based for loop
for(int e : vector) // 복사
for(int& e: vector) // 참

**연결 리스트**
연결 리스트의 성질
1. k번째 원소를 확인/변경하기 위해 O(k)가 필요함
2. 임의의 위치에 원소를 추가/임의 위치의 원소 제거는 O(1)
3. 원소들이 메모리 상에 연속해있지 않아 Cache hit rate가 낮지만 할당이 다소 쉬

연결 리스트의 종류
1. 단일 연결 리스트
2. 이중 연결 리스트 ※STL list
3. 원형 연결 리스트

배열과 연결 리스트의 차이 (배열, 연결 리스트)
k번째 원소의 접근 : O(1), O(k)
임의 위치에 원소 추가/제거 : O(N), O(1)
메모리 상의 배치 : 연속, 불연속
추가적으로 필요한 공간 : -, O(N)

야매 연결 리스트
const int MX = 10000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;
fill(pre, pre+MX, -1);
fill(nxt, nxt+MX, -1);

손코딩 문제
1. 원형 연결 리스트 내의 임의의 노드 하나가 주어졌을 때 해당 List의 길이? O(N)
2. 중간에 만나는 두 연결 리스트의 시작점들이 주어졌을 때 만나는 지점을 구하는 방법? O(A+B)
3. 연결 리스트 안에 사이클 확인법? O(N)
Floyd's cycle-finding algorithm : cursor speed 1, 2로 출발시키면 cycle이 있으면 두 커서는 반드시 만난다.

**스택/큐/덱(Restricted Structure)**
스택 : FILO

스택의 성질
1. 원소의 추가 : O(1)
2. 원소의 제거 : O(1)
3. 제일 상단의 원소 확인 : O(1)
4. 제일 상단이 아닌 나머지 원소들의 확인/변경 불가능

스택의 구현
const int MX = 1000005;
int dat[MX];
int pos = 0; // pos(idx) = top + 1

큐 : FIFO

큐의 성질
1. 원소의 추가 O(1)
2. 원소의 제거 O(1)
3. 제일 앞/뒤의 원소 확인 O(1)
4. 나머지 원소들의 확인/변경이 불가능

스택의 구현
const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

스택 STL
Q.push()
Q.pop()
Q.front()
Q.back()
Q.size()
Q.empty()

Sort

Select sort : O(N^2)
Bubble sort : O(N^2)

Merge sort : O(N)
*Stable sort -> 같은 값의 순서가 있음