#include <bits/stdc++.h>
using namespace std;

bool isEncap(vector<vector<bool>>& vec, int x, int y, int size) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (vec[x][y] != vec[i][j]) return 0;
		}
	}
	return 1;
}

string QuadTree(vector<vector<bool>>& vec, int x, int y, int size) {
	string digit = "";
	if (size <= 1) return to_string(vec[x][y]);
	
	if (isEncap(vec, x, y, size)) {
		return to_string(vec[x][y]);
	}
	else {
		int newsize = size / 2;

		digit += '(';
		digit += QuadTree(vec, x, y, newsize);
		digit += QuadTree(vec, x, y + newsize, newsize);
		digit += QuadTree(vec, x + newsize, y, newsize);
		digit += QuadTree(vec, x + newsize, y + newsize, newsize);
		digit += ')';
	}

	return digit;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<bool>> vec(N + 1, vector<bool>(N + 1));

	for (int i = 1; i <= N; i++) {
		string input;
		cin >> input;

		int j = 1;
		for (auto b : input) {
			vec[i][j++] = b - '0';
		}
	}

	cout << QuadTree(vec, 1, 1, N);

	return 0;
}