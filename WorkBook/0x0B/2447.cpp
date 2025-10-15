#include <bits/stdc++.h>
using namespace std;

void recursive_void(int x, int y, int size, vector<vector<char>>& vec) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			vec[i][j] = ' ';
		}
	}
}

void recursive(int x, int y, int size, vector<vector<char>>& vec) {
	if (size <= 2) return;

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			vec[i][j] = '*';
		}
	}

	int newsize = size / 3;

	recursive(x, y, newsize, vec);
	recursive(x + newsize, y, newsize, vec);
	recursive(x + newsize * 2, y, newsize, vec);

	recursive(x, y + newsize, newsize, vec);
	recursive_void(x + newsize, y + newsize, newsize, vec);
	recursive(x + newsize * 2, y + newsize, newsize, vec);

	recursive(x, y + newsize * 2, newsize, vec);
	recursive(x + newsize, y + newsize * 2, newsize, vec);
	recursive(x + newsize * 2, y + newsize * 2, newsize, vec);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<char>> vec(N, vector<char>(N));

	recursive(0, 0, N, vec);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << vec[i][j];
		}
		cout << '\n';
	}

	return 0;
}