#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];

void BackTracking(int K) {
    if (K == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        arr[K] = i;
        BackTracking(K + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    BackTracking(0);

    return 0;
}