#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int M = N - 1;
    while (N--) {
        for (int i = M; i > N; i--) cout << ' ';
        for (int i = 0; i <= N; i++) cout << '*';
        cout << '\n';
    }

    return 0;
}