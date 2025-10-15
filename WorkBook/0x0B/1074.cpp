#include <bits/stdc++.h>
using namespace std;

int recursive(int N, int R, int C) {
	if (N == 0) return 0;
	int H = 1 << (N - 1);
	if (R < H && C < H) return recursive(N - 1, R, C);
	if (R < H && C >= H) return H * H + recursive(N - 1, R, C - H);
	if (R >= H && C < H) return 2 * H * H + recursive(N - 1, R - H, C);
	return 3 * H * H + recursive(N - 1, R - H, C - H);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, C, R;
	cin >> N >> R >> C;
	cout << recursive(N, R, C);

	return 0;
}