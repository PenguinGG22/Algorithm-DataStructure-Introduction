#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    int Y = 0, M = 0;
    while (T--) {
        int I;
        cin >> I;
        Y += (I / 30 + 1) * 10;
        M += (I / 60 + 1) * 15;
    }
    if (Y < M) {
        cout << 'Y' << ' ' << Y;
    }
    else if (Y > M) {
        cout << 'M' << ' ' << M;
    }
    else {
        cout << 'Y' << ' ' << 'M' << ' ' << Y;
    }

    return 0;
}