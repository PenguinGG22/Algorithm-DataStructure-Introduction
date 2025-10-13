#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    stack<int> s;
    vector<char> result;
    int current_num = 1;

    for (int i = 0; i < n; ++i) {
        int target;
        cin >> target;

        while (current_num <= target) {
            s.push(current_num);
            result.push_back('+');
            current_num++;
        }

        if (s.top() == target) {
            s.pop();
            result.push_back('-');
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    for (char op : result) {
        cout << op << '\n';
    }

    return 0;
}