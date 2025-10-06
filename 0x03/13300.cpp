#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> room(7, vector<int>(2, 0)); // 학년, 성별
    int N, K;
    cin >> N >> K;
    while (N--) {
        int S, Y;
        cin >> S >> Y;
        room[Y][S]++;
    }
    
    int cnt = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j <= 1; j++) {
            cnt += room[i][j] / K;
            if (room[i][j] % K != 0) cnt++;
        }
    }
    cout << cnt;

    return 0;
}