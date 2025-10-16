#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M;

int board[100][100];
int vis[100][100];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int i, int j) {
	queue<pair<int, int>> Q;
	vis[i][j] = 1;
	Q.push({ i,j });

	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] != 1 || vis[nx][ny] > 0) continue;

			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;

		for (int j = 0; j < M; j++) {
			board[i][j] = S[j] - '0';
		}
	}

	BFS(0, 0);
	cout << vis[N - 1][M - 1];

	return 0;
}