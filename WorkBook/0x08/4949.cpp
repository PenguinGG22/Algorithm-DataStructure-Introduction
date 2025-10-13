#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		string str;
		getline(cin, str);

		if (str == ".") {
			return 0;
		}

		stack<char> s;
		int isVal = true;

		for (char c : str) {
			if (c == '(' || c == '[') {
				s.push(c);
			}
			else if (c == ')') {
				if (s.empty() || s.top() == '[') {
					isVal = false;
					break;
				}
				s.pop();
			}
			else if (c == ']') {
				if (s.empty() || s.top() == '(') {
					isVal = false;
					break;
				}
				s.pop();
			}
		}

		if (s.empty() && isVal) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}