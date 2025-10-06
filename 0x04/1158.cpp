#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    deque<int> deq;
    vector<int> vec;
    for (int i = 0; i < N; i++) {
        deq.push_back(i + 1);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K - 1; j++) {
            int tmp = deq.front();
            deq.push_back(tmp);
            deq.pop_front();
        }
        int fnt = deq.front();
        vec.push_back(fnt);
        deq.pop_front();
    }

    cout << '<';
    for (int i = 0; i < N - 1; i++) {
        cout << vec[i] << ',' << ' ';
    }
    cout << vec.back() << '>';

    return 0;
}