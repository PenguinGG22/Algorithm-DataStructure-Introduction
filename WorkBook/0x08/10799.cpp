#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin >> S;

    int stk = 0;
    int cnt = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(') {
            stk++;
        }
        else {
            stk--;
            if (S[i - 1] == '(') {
                cnt += stk;
            }
            else {
                cnt += 1;
            }
        }
    }
    cout << cnt;

    return 0;
}