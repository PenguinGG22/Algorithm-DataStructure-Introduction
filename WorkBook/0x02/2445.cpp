#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = N; i > 1; i--) {
        for (int j = 0; j < N - i + 1; j++) cout << '*';
        for (int j = 1; j < 2 * i - 1; j++) cout << ' ';
        for (int j = 0; j < N - i + 1; j++) cout << '*';
        cout << '\n';
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i; j++) cout << '*';
        for (int j = 1; j < 2 * (i + 1) - 1; j++) cout << ' ';
        for (int j = 0; j < N - i; j++) cout << '*';
        cout << '\n';
    }

    return 0;
}