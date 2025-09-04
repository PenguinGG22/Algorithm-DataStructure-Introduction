#include <bits/stdc++.h>
using namespace std;

int dat[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	
	int head = 0, rear = 0;
	while (N--) {
		string execution;
		cin >> execution;
		if (execution == "push") {
			int add;
			cin >> add;
			dat[rear++] = add;
		}
		else if (execution == "pop") {
			if (head != rear) cout << dat[head++] << '\n';
			else cout << -1 << '\n';
		}
		else if (execution == "size") {
			cout << rear - head << '\n';
		}
		else if (execution == "empty") {
			if (head == rear) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (execution == "front") {
			if (head != rear) cout << dat[head] << '\n';
			else cout << -1 << '\n';
		}
		else {
			if (head != rear) cout << dat[rear - 1] << '\n';
			else cout << -1 << '\n';
		}
	}
	return 0;
}