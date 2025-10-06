#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> vec(9);

    for (int i = 0; i < 9; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (j == i) continue;
            int sum = 0;
            for (int k = 0; k < 9; k++) {
                if (k == i || k == j) continue;
                sum += vec[k];
            }
            if (sum == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k == i || k == j) continue;
                    cout << vec[k] << '\n';
                }
                return 0;
            }
        }
    }

    return 0;
}