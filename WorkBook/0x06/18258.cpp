#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int N;
    cin >> N;
    
    queue<int> que;

    while (N--) {
        string command;
        cin >> command;
        if (command == "push") {
            int add;
            cin >> add;
            que.push(add);
        }
        else if (command == "pop") {
            if (que.empty()) cout << -1 << '\n';
            else {
                cout << que.front() << '\n';
                que.pop();
            }
        }
        else if (command == "size") {
            cout << que.size() << '\n';
        }
        else if (command == "empty") {
            if (que.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (command == "front") {
            if (que.empty()) cout << -1 << '\n';
            else cout << que.front() << '\n';
        }
        else {
            if (que.empty()) cout << -1 << '\n';
            else cout << que.back() << '\n';
        }
    }

    return 0;
}