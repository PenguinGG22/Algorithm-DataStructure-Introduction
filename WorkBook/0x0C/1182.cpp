#include <bits/stdc++.h>
using namespace std;

int arr[50];
bool isUsed[50];
int N, S, cnt;

void BackTracking(int k, int st, int sum) {
	if (k == N) {
		return;
	}

	for (int i = st; i < N; i++) {
		if (sum == S) {
			cnt++;
			continue;
		}
		sum += arr[i];
		isUsed[i] = true;
		BackTracking(k + 1, i + 1, sum);
		isUsed[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	BackTracking(0, 0, 0);
	cout << cnt;

	return 0;
}
