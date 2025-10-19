#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
bool isUsed[10];

void BackTracking(int K) {
    if (K == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!isUsed[i]) {
            arr[K] = i;
            isUsed[i] = 1;
            BackTracking(K + 1);
            isUsed[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    BackTracking(0);

    return 0;
}