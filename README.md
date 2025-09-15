# Algorithm-Introduction

### Online Judge STL/IO Setting
```cpp
#include <bits/stdc++.h>
ios_base::sync_with_stdio(false);
cin.tie(NULL);
```

### 시간 복잡도
입력의 크기와 문제를 해결하는데 걸리는 시간의 상관관계

### 빅오 표기법
주어진 식을 값이 가장 큰 대표항만 남겨서 나타내는 방법
```
O(1) < O(lgN) < O(N) < O(NlgN) < O(N^2) < O(2^n) < O(N!)
```

### 공간 복잡도
입력의 크기와 문제를 해결하는데 필요한 공간의 상관관계
```
512MB = 1.2억개의 int자료형을 사용 가능
```

> Example code : TimeComplexity.cpp  

### 정수 자료형
short(2byte) < int(4byte) < long long (8byte)

### 실수 자료형
float(4byte) < double(8byte)

float: sign(1) + exponent(8) + fraction (23)
double: sign(1) + exponent(11) + fraction (52)

### 실수 자료형 주의사항
1. 실수의 저장/연산 과정에서 반드시 오차가 발생할 수 밖에 없다.
2. double에 long long 범위의 정수를 함부로 담으면 안된다.
3. 실수를 비교할 때는 등호를 사용하면 안된다.

### STL
Vector를 복사하는 시간 복잡도 : O(N)
Vector를 참조하는 시간 복잡도 : O(1)

### String 입력 함수
```
getline(cin, str);
```

## 배열
### 배열의 정의
메모리 상에 원소를 연속하게 배치한 자료구조

### 배열의 성질
1. O(1)에 k번째 원소를 확인/변경 가능
2. 추가적으로 소모되는 메모리의 양(=overhead)가 거의 없음
3. Cache hit rate가 높음
4. 메모리 상에 연속한 구간을 잡아야 해서 할당에 제약이 걸림
```
Cache hit rate : CPU가 필요한 데이터를 Cache memory에서 성공적으로 찾은 비율
Overhead : 작업을 처리하는데 간접적으로 필요한 자원이나 시간 (Pointer)
```

### 배열의 시간복잡도
1. 임의의 위치에 있는 원소를 확인/변경 : O(1)
2. 마지막 위치의 원소를 추가/제거 : O(1)
3. 임의의 위치에 원소를 추가/제거 : O(N)
```
k번에 추가된다면, k이후의 원소들을 한칸씩 밀고, 땡기기 때문이다.
```
> Example Code : Array1.cpp  

### 배열의 초기화 함수
```
fill(arr, arr + arr_size, 0);
```
## Vector
### STL vector
> Example Code : Vector.cpp  

### Range-based for loop
for(int e : vector) : vector의 원소에 복사 접근
for(int& e: vector) : vector의 원소에 직접 접근
> Soultion Code : 10808.cpp  
> Example Code : Func2.cpp  

## 연결 리스트
### 연결 리스트의 정의
데이터와 다음 노드를 가르키는 링크를 가진 노드들이 한 줄로 연결된 자료구조
### 연결 리스트의 성질
1. k번째 원소를 확인/변경하기 위해 O(k)가 필요함
2. 임의의 위치에 원소를 추가/임의 위치의 원소 제거는 O(1)
3. 원소들이 메모리 상에 연속해있지 않아 Cache hit rate가 낮지만 할당이 쉬움
```
Cache hit rate : CPU가 필요한 데이터를 Cache memory에서 성공적으로 찾은 비율
Overhead : 작업을 처리하는데 간접적으로 필요한 자원이나 시간 (Pointer)
```

### 연결 리스트의 종류
1. 단일 연결 리스트 (Singly Linked List)
2. 이중 연결 리스트 (Doubly Linked List)
> STL list = 이중 연결 리스트  
3. 원형 연결 리스트 (Circular Linked List)

### 연결 리스트의 시간 복잡도
1. 임의의 위치에 있는 원소를 확인/변경 : O(N)
2. 임의의 위치에 있는 원소를 추가/제거 : O(1)

### 연결 리스트의 구현
> Example Code : Linked-list1.cpp  
> Example Code : Linked-list2.cpp  
> Solution Code : 1406.cpp  

### 연결 리스트 문제
1. 원형 연결 리스트 내의 임의의 노드 하나가 주어졌을 때 해당 List의 길이?
> O(N)  
2. 중간에 만나는 두 연결 리스트의 시작점들이 주어졌을 때 만나는 지점을 구하는 방법?
> O(A+B)  
3. 연결 리스트 안에 사이클 확인법?
> O(N)  
```
Floyd's cycle-finding algorithm : cursor speed 1, 2로 출발시키면 cycle이 있으면 두 커서는 반드시 만난다.
```

## 스택
### 스택의 정의
마지막에 들어온 데이터가 가장 먼저 나가는 특징을 가진 자료구조 (LIFO)

### 스택의 성질
1. 원소의 추가/제거 : O(1)
2. 제일 상단의 원소 확인 : O(1)
3. 제일 상단이 아닌 나머지 원소들의 확인/변경 불가능

### 스택의 구현
```
const int MX = 1000005;
int dat[MX];
int pos = 0;
```
> Example code : Stack1.cpp  
> Example code : Stack2.cpp  
> Solution code : 10828_1.cpp  
> Solution code : 10828_2.cpp  

## 큐
### 큐의 정의
먼저 들어온 데이터가 가장 먼저 나가는 특징을 가진 자료구조 (FIFO)

### 큐의 성질
1. 원소의 추가/제거 : O(1)
2. 제일 앞/뒤의 원소 확인 : O(1)
3. 나머지 원소들의 확인/변경이 불가능

### 스택의 구현
```
const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;
```
> Example code : Queue1.cpp  
> Example code : Queue2.cpp  
> Solution code : 10845_1.cpp  
> Solution code : 10845_2.cpp  

## 덱 (deque : double ended queue)
### 덱의 정의 
양쪽 끝에서 삽입과 삭제가 가능한 자료구조 (LIFO + FIFO)

### 덱의 성질
1. 원소의 추가/제거 : O(1)
2. 제일 앞/뒤의 원소 확인 O(1)
3. 나머지 원칙적 불가

### 덱의 구현
```
const int MX = 1000005;
int dat[2*MX+1];
int head = MX, tail = MX;
```
> Example code : Deque1.cpp  
> Example code : Deque2.cpp  
> Solution code : 10866_1.cpp  
> Solution code : 10866_2.cpp  

## 수식의 괄호 쌍
### 수식의 괄호 쌍의 정의
주어진 괄호 문자열이 올바른지 판단하는 것

### 스택의 활용
문자열을 앞에서부터 읽어 나갈때, 닫는 괄호는 남아있는 괄호 중에서 가장 최근에 들어온 여는 괄호와 짝을 지어 없애버린다.

### 문제 해결 방법
1. 여는 괄호가 나오면 스택에 추가
2. 닫는 괄호가 나왔을 경우
- 스택이 비어 있으면, 올바르지 않은 괄호 쌍
- 스택의 top이 짝이 맞지 않는 괄호일 경우 올바르지 않은 괄호 쌍
- 스택의 top이 짝이 맞는 괄호일 경우 pop
3. 모든 과정을 끝낸 후 스택에 괄호가 남아있으면 올바르지 않은 괄호쌍, 남아있지 않으면 올바른 괄호 쌍
> Solution code : 4849.cpp  
> Solution code : 10799.cpp  
> Solution code : 2504.cpp  

## BFS
### BFS의 정의
다차원 배열에서 각 칸을 방문할때 너비를 우선으로 방문하는 알고리즘 (Breadth)

### 문제 해결 방법
1. 시작하는 칸을 큐에 넣고 방문했다는 표시를 남김
2. 큐에서 원소를 꺼내어 그 칸에 상하좌우로 인접한 칸에 대해 3번을 진행
3. 해당 칸을 이전에 방문했다면 아무것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 큐에 삽입
4. 큐가 빌때 까지 2번을 반복  
모든 칸이 큐에 1번씩 들어가므로 시간 복잡도는 칸이 N개일때 O(N)
> Example code : Pair.cpp  
> Example code : BFS.cpp  
> Solution code : 2178.cpp  
> Solution code : 7576.cpp  
> Solution code : 4179.cpp  
> Solution code : 1697.cpp  

## DFS
### DFS의 정의
다차원 배열에서 각 칸을 방문할 때 깊이를 우선으로 방문하는 알고리즘 (Depth)

### 문제 해결 방법
1. 시작하는 칸을 스택에 넣고 방문했다는 표시를 남김
2. 스택에서 원소를 꺼내어 그 칸과 상하좌우로 인접한 칸에 대해 3번을 진행
3. 해당 칸을 이전에 방문했다면 아무것도 하지않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 스택에 삽입
4. 스택이 빌때까지 2번을 반복  
모든 칸이 스택에 1번씩 들어가므로 시간복잡도는 칸이 N개일때 O(N)
> Example code : DFS.cpp  

## 재귀
### 재귀의 정의
하나의 함수에서 자기 자신을 다시 호출해 작업을 수행하는 알고리즘



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