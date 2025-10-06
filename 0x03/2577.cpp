#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;
	long long result = A * B * C;
	string str = to_string(result);

	for (char c = '0'; c <= '9'; c++) {
		int cnt = 0;
		for (int i = 0; i < str.size(); i++) {
			if (c == str[i]) cnt++;
		}
		cout << cnt << '\n';
	}

	return 0;
}