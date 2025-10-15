#include <bits/stdc++.h>
using namespace std;

int white_count = 0;
int blue_count = 0;
vector<vector<int>> paper;

bool isSame(int x, int y, int size) {
    int first_color = paper[x][y];
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (paper[i][j] != first_color) {
                return false;
            }
        }
    }
    return true;
}

void seperate(int x, int y, int size) {
    if (isSame(x, y, size)) {
        if (paper[x][y] == 0) {
            white_count++;
        }
        else {
            blue_count++;
        }
        return;
    }

    int new_size = size / 2;
    seperate(x, y, new_size);
    seperate(x, y + new_size, new_size);
    seperate(x + new_size, y, new_size);
    seperate(x + new_size, y + new_size, new_size);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    paper.resize(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> paper[i][j];
        }
    }

    seperate(0, 0, N);

    cout << white_count << '\n';
    cout << blue_count << '\n';

    return 0;
}