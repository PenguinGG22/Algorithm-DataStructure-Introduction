#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 0;
    int min = 100;
    for (int i = 0; i < 7; i++) {
        int input;
        cin >> input;
        if (input % 2 == 1) {
            cnt += input;
            if (input < min) min = input;
        }
    }
    if (min == 100) {
        cout << -1;
        return 0;
    }
    cout << cnt << '\n' << min;

    return 0;
}