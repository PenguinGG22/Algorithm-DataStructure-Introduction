#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;

    vector<int> count1(26, 0);
    vector<int> count2(26, 0);

    for (char c : str1) {
        count1[c - 'a']++;
    }

    for (char c : str2) {
        count2[c - 'a']++;
    }

    int total_deletions = 0;
    for (int i = 0; i < 26; i++) {
        total_deletions += abs(count1[i] - count2[i]);
    }

    cout << total_deletions;

    return 0;
}