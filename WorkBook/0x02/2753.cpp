#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    if (N % 4 == 0 && (N % 100 != 0 || N % 400 == 0)) cout << true;
    else cout << false;

    return 0;
}