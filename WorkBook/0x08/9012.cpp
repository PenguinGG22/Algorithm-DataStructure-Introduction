#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		bool isVPS = true;
		stack<int> stack;
		string str;
		cin >> str;

		for (char c : str) {
			if (c == '(') stack.push(0);
			else {
				if (!stack.empty()) {
					stack.pop();
				}
				else {
					isVPS = false;
				}
			}
		}
		if (stack.empty() && isVPS) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}

	return 0;
}