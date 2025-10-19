#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int num[10];
bool isUsed[10];

void BackTracking(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!isUsed[i]) {
            arr[k] = num[i];
            isUsed[i] = true;
            BackTracking(k + 1);
            isUsed[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    sort(num, num + N);
    BackTracking(0);

    return 0;
}
