#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[21];
    for (int i = 1; i <= 20; i++) {
        arr[i] = i;
    }
    for(int i=0; i<10; i++) {
        int A, B;
        cin >> A >> B;
        for (int j = 0; j <= (B - A) / 2; j++) {
            swap(arr[A + j], arr[B - j]);
        }
    }
    for (int i = 1; i <= 20; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}