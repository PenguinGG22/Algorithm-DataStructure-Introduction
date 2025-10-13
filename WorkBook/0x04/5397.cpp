#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        string PW = "";
        cin >> PW;
        list<char> L;
        list<char>::iterator it = L.begin();

        for (char c : PW) {
            if (c == '<') {
                if (it != L.begin()) {
                    it--;
                }
            }
            else if (c == '>') {
                if (it != L.end()) {
                    it++;
                }
            }
            else if (c == '-') {
                if (it != L.begin()) {
                    it--;
                    it = L.erase(it);
                }
            }
            else {
                L.insert(it, c);
            }
        }
        for (char c : L) {
            cout << c;
        }
        cout << '\n';
    }
    return 0;
}