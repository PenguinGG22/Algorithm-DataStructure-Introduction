#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> vec(10);
    string str;
    cin >> str;

    for (char c : str) {
        int idx = c - '0';
        vec[idx]++;
    }

    int max = (vec[6] + vec[9] + 1) / 2;
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9) continue;
        if (max < vec[i]) max = vec[i];
    }
    cout << max;

    return 0;
}