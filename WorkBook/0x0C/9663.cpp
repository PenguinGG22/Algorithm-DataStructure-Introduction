#include <bits/stdc++.h>
using namespace std;

bool isUsed1[50];
bool isUsed2[50];
bool isUsed3[50];

int N, cnt;

void BackTracking(int k) {
	if (k == N) {
		cnt++;
		return;
	}
	
	for (int i = 0;i < N;i++) {
		if (isUsed1[i] || isUsed2[i + k] || isUsed3[k - i + N - 1]) continue;
		isUsed1[i] = true;
		isUsed2[i + k] = true;
		isUsed3[k - i + N - 1] = true;

		BackTracking(k + 1);

		isUsed1[i] = false;
		isUsed2[i + k] = false;
		isUsed3[k - i + N - 1] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	BackTracking(0);
	cout << cnt;

	return 0;
}
