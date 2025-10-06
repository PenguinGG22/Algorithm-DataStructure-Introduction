#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    for(char i='a'; i<='z'; i++){
        int cnt = 0;
        for(int j=0; j<s.size(); j++){
            if(s[j]==i) cnt++;
        }
        cout << cnt << ' ';
    }

    return 0;
}