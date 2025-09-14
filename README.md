# Algorithm-Introduction

## ⏳ 시간 복잡도 & 공간 복잡도

### 1. 시간 복잡도 (Time Complexity)

- **정의**: 문제 해결에 걸리는 시간과 입력 크기 간의 상관관계입니다.
- 알고리즘의 효율성을 평가하는 중요한 척도입니다.

#### 빅오(Big-O) 표기법

- **정의**: 알고리즘의 시간 복잡도를 나타내는 가장 일반적인 방법으로, 데이터 처리량이 증가할 때 성능의 상한선(최악의 경우)을 간결하게 표현합니다.
- 성능 순서는 아래와 같으며, 왼쪽으로 갈수록 효율적인 알고리즘입니다.

```
O(1) < O(log N) < O(N) < O(N log N) < O(N^2) < O(2^n) < O(N!)
```

<br>

### 2. 공간 복잡도 (Space Complexity)

- **정의**: 문제 해결에 필요한 메모리(공간)와 입력 크기 간의 상관관계입니다.
- 시간 복잡도와 함께 알고리즘의 성능을 분석하는 데 사용됩니다.

> **💡 메모리 크기 참고**
>
> - 일반적으로 **512MB**의 메모리가 주어질 경우, `int` 자료형 약 **1억 2천만 개**를 선언하여 사용할 수 있습니다.

---

## 🔢 정수 및 실수 자료형

### 1. 정수 자료형 (Integer Types)

- 데이터의 크기에 따라 적절한 자료형을 선택하는 것이 중요합니다.
- **short** (2 bytes) < **int** (4 bytes) < **long long** (8 bytes)

<br>

### 2. 실수 자료형 (Floating-Point Types)

- 실수는 부동소수점 방식으로 저장되며, 이 과정에서 오차가 발생할 수 있습니다.
- **float** (4 bytes) < **double** (8 bytes)

- **`float`**: sign(1 bit) + exponent(8 bits) + fraction(23 bits)
- **`double`**: sign(1 bit) + exponent(11 bits) + fraction(52 bits)

#### ⚠️ 실수 자료형 사용 시 핵심 주의사항

1.  **오차 발생 가능성**
    - 실수를 컴퓨터에 저장하고 연산하는 과정에서는 필연적으로 **근삿값으로 처리되어 오차가 발생**할 수 있습니다.

2.  **큰 정수 저장 문제**
    - `double`은 `long long`보다 표현 범위는 넓지만, 정수를 저장하는 **정밀도(가수부)에는 한계**가 있습니다. `long long` 범위의 아주 큰 정수를 `double`에 담으면 값이 깨질 수 있습니다.

3.  **실수 비교 방법**
    - 오차 때문에 `==` 연산자로 두 실수가 같은지 직접 비교하면 안 됩니다.
    - 두 실수의 차이가 아주 작은 값(엡실론, e.g., `1e-9`)보다 작은지를 확인하는 방식으로 비교해야 합니다.

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

덱 : LIFO + FIFO
덱의 성질
1. 원소의 추가 O(1)
2. 원소의 제거 O(1)
3. 제일 앞/뒤의 원소 확인 O(1)
4. 나머지 원칙적 불가

덱의 구현
const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;

Sort

Select sort : O(N^2)
Bubble sort : O(N^2)

Merge sort : O(N)
*Stable sort -> 같은 값의 순서가 있음

**Dynamic Programming, DP**
여러개의 하위 문제를 먼저 푼 후, 그 결과를 쌓아올려 주어진 문제를 해결하는 알고리즘 (문제의 하위 점화식을 쌓아올려서 해결함)

DP를 푸는 과정
1. 테이블 정의 (경험)
2. 점화식 찾기
3. 초기값 설정

연습 문제
1463.cpp
9095.cpp
2579.cpp