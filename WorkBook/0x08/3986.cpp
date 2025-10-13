#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int cnt = 0;
    while (N--) {
        stack<char> stk;
        string S;
        cin >> S;

        for (int i = 0; i < S.length(); i++) {
            if (!stk.empty() && stk.top() == S[i]) {
                stk.pop();
            }
            else {
                stk.push(S[i]);
            }
        }
        if (stk.empty()) cnt++;
    }
    cout << cnt;

    return 0;
}