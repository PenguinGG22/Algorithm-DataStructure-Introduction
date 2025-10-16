#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M;
int cnt, max_size;

int board[500][500];
int vis[500][500];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int i, int j) {
	queue<pair<int, int>> Q;
	vis[i][j] = 1;
	Q.push({ i,j });
	int size = 1;

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 4; i++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;

			size++;
			vis[nx][ny] = 1;
			Q.push({ nx,ny });
		}
	}

	if (size > max_size) max_size = size;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1 && vis[i][j] == 0) {
				BFS(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << '\n';
	cout << max_size;

	return 0;
}