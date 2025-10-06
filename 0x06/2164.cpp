#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int N;
    cin >> N;
    
    queue<int> que;

    for (int i = 1; i <= N; i++) {
        que.push(i);
    }

    while (que.size() > 1) {
        que.pop();
        int tmp = que.front();
        que.pop();
        que.push(tmp);
    }

    cout << que.front();

    return 0;
}