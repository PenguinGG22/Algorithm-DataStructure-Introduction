#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	stack<int> stack;

	while (N--) {
		int command;
		cin >> command;
		if (command == 0) {
			stack.pop();
		}
		else {
			stack.push(command);
		}
	}

	if (stack.empty()) {
		cout << 0;
		return 0;
	}

	int cnt = 0;
	while(!stack.empty()) {
		cnt += stack.top();
		stack.pop();
	}
	cout << cnt;

	return 0;
}