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

Sort

Select sort : O(N^2)
Bubble sort : O(N^2)

Merge sort : O(N)
*Stable sort -> 같은 값의 순서가 있음