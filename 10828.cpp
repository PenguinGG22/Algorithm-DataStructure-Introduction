#include <bits/stdc++.h>
using namespace std;

int dat[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int pos = 0;
	while (N--) {
		string execution;
		cin >> execution;
		if (execution == "push") {
			int add;
			cin >> add;
			dat[pos++] = add;
		}
		else if (execution == "pop") {
			if (pos == 0) cout << -1 << '\n';
			else {
				cout << dat[pos - 1] << '\n';
				pos--;
			}
		}
		else if (execution == "size") {
			cout << pos << '\n';
		}
		else if (execution == "empty") {
			if (pos == 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else {
			if (pos == 0) cout << -1 << '\n';
			else cout << dat[pos - 1] << '\n';
		}
	}

	return 0;
}