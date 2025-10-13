#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    long long result = 0;
    int temp = 1;
    stack<char> stk;

    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (c == '(') {
            temp *= 2;
            stk.push(c);
        } else if (c == '[') {
            temp *= 3;
            stk.push(c);
        } else if (c == ')') {
            if (stk.empty() || stk.top() != '(') {
                result = 0;
                break;
            }
            if (s[i - 1] == '(') {
                result += temp;
            }
            stk.pop();
            temp /= 2;
        } else if (c == ']') {
            if (stk.empty() || stk.top() != '[') {
                result = 0;
                break;
            }
            if (s[i - 1] == '[') {
                result += temp;
            }
            stk.pop();
            temp /= 3;
        }
    }

    if (!stk.empty()) {
        result = 0;
    }

    cout << result << '\n';

    return 0;
}