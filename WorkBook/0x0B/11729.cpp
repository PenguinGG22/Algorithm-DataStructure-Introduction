#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int from, int via, int to) {
    if (n == 1) {
        cout << from << " " << to << "\n";
    }
    else {
        hanoi(n - 1, from, to, via);
        cout << from << " " << to << "\n";
        hanoi(n - 1, via, from, to);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int k = static_cast<int>(pow(2, N)) - 1;
    cout << k << "\n";

    hanoi(N, 1, 2, 3);

    return 0;
}