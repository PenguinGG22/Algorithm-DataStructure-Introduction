#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<char> vec(26);

    int T;
    cin >> T;
    while (T--) {
        string S, F;
        cin >> S >> F;

        for (char c : F) {
            int idx;
            if (islower(c)) {
                idx = c - 'a';
            }
            else {
                idx = c - 'A';
            }
            vec[idx]++;
        }

        for (char c : S) {
            int idx;
            if (islower(c)) {
                idx = c - 'a';
            }
            else {
                idx = c - 'A';
            }
            vec[idx]--;
        }

        bool isStrfry = true;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] != 0) isStrfry = false;
        }

        if (isStrfry) cout << "Possible" << '\n';
        else cout << "Impossible" << '\n';

        fill(vec.begin(), vec.end(), 0);
    }
    return 0;
}