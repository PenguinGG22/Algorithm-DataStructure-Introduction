#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> Q;
	int N;
	cin >> N;
	while (N--) {
		string execution;
		cin >> execution;
		if (execution == "push") {
			int add;
			cin >> add;
			Q.push(add);
		}
		else if (execution == "pop") {
			if (Q.empty()) cout << -1;
			else {
				cout << Q.front();
				Q.pop();
			}
			cout << '\n';
		}
		else if (execution == "size") {
			cout << Q.size() << '\n';
		}
		else if (execution == "empty") {
			cout << Q.empty() << '\n';
		}
		else if (execution == "front") {
			if (Q.empty()) cout << -1 << '\n';
			else cout << Q.front() << '\n';
		}
		else {
			if (Q.empty()) cout << -1 << '\n';
			else cout << Q.back() << '\n';
		}
	}

	return 0;
}