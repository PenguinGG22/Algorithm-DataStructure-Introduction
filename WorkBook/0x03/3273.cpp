#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<bool> vec(2000001);
    for (int i = 0; i < N; i++) {
        int G;
        cin >> G;
        vec[G] = true;
    }

    int X;
    cin >> X;
    int cnt = 0;
    for (int i = 1; i < (X + 1) / 2; i++) {
        if (vec[i] && vec[X - i])
            cnt++;
    }

    cout << cnt;

    return 0;
}