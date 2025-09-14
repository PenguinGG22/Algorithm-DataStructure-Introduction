// 문제 1 : N 이하의 자연수 중에서 3의 배수이거나 5의 배수인 수를 모두 합한 값을 반환하는 func1(int N)을 작성하라.
int func1(int N) {
	int sum = 0;
	for (int i = 1; i <= N; ++i) {
		if (i % 3 == 0 || i % 5 == 0) sum += i;
	}
	return sum;
}
// 시간복잡도 : O(N)

// 문제 2 : 주어진 길이 N의 배열 arr에서 합이 100인 서로 다른 위치의 두 원소가 존재하면 1을,
// 존재하지 않으면 0을 반환하는 함수 func2(int arr[], int N)을 작성해라.
bool func2(int arr[], int N) {
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (arr[i] + arr[j] == 100) return 1;
		}
	}
	return 0;
}
// 시간복잡도 : O(N^2)

// 문제 3 : N이 제곱수이면 1을 반환하고 제곱수가 아니면 0을 반환하는 함수 func3(int N)을 작성해라.
bool func3(int N) {
	for (int i = 0; i * i <= N; ++i) {
		if (i * i == N) return 1;
	}
	return 0;
}
// 시간복잡도 : O(root(N))

// 문제 4 : N이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는 함수 func4(int N)을 작성해라.
bool func4(int N) {
	int val = 1;
	while (2 * val <= N) val *= 2;
	return val;
}
// 시간복잡도 : O(lgN)