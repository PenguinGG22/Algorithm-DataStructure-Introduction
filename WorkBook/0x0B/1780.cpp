#include <bits/stdc++.h>
using namespace std;

int arr[3];

bool isSame(vector<vector<int>>& vec, int x, int y, int size) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (vec[x][y] != vec[i][j]) return false;
		}
	}
	return true;
}

void Matrix(vector<vector<int>>& vec, int x, int y, int size) {
	if (size<=1) {
		arr[vec[x][y] + 1]++;
		return;
	}

	int newsize = size / 3;
	if (isSame(vec, x, y, size)) {
		arr[vec[x][y] + 1]++;
		return;
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				Matrix(vec, x + i * newsize, y + j * newsize, newsize);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> vec(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> vec[i][j];
		}
	}

	Matrix(vec, 0, 0, N);

	std::cout << arr[0] << '\n';
	std::cout << arr[1] << '\n';
	std::cout << arr[2] << '\n';
	
	return 0;
}