#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string init;
	cin >> init;
	list<char> L;
	for (auto c : init) L.push_back(c);
	auto cursor = L.end();
	int n;
	cin >> n;
	while (n--) {
		char ex;
		cin >> ex;
		if (ex == 'L') {
			if (cursor != L.begin()) cursor--;
		}
		else if (ex == 'D') {
			if (cursor != L.end()) cursor++;
		}
		else if (ex == 'B') {
			if (cursor != L.begin()) {
				cursor--;
				cursor = L.erase(cursor);
			}
		}
		else {
			char add;
			cin >> add;
			L.insert(cursor, add);
		}
	}
	for (auto c : L) cout << c;
	
	return 0;
}