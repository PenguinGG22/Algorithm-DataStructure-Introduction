#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int num[10];
bool isUsed[10];

void BackTracking(int k, int st) {
    if (k == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int tmp = 0;
    for (int i = st; i < N; i++) {
        if (!isUsed[i] && num[i] != tmp) {
            arr[k] = num[i];
            isUsed[i] = true;
            tmp = num[i];
            BackTracking(k + 1, i);
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
    BackTracking(0, 0);

    return 0;
}
