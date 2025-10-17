#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0 , -1 };

int board[52][52];
int dist[52][52];

int N, M;

/* printing board and dist

void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

*/

void BFS(int R, int C) {
    queue<pair<int, int>> Q;
    dist[R][C] = 1;
    Q.push({ R,C });
    while (!Q.empty()) {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] != 1 || dist[nx][ny] == 1) continue;

            dist[nx][ny] = 1;
            Q.push({ nx,ny });
        }
    }

    // print();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        for (int i = 0; i < 52; ++i) {
            fill(board[i], board[i] + 52, 0);
            fill(dist[i], dist[i] + 52, 0);
        }

        int K;
        cin >> M >> N >> K;

        while (K--) {
            int X, Y;
            cin >> X >> Y;
            board[Y][X] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 1 && dist[i][j] != 1) {
                    BFS(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}