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

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    // a부터 z까지 26개의 공간을 가진 배열을 0으로 초기화
    int alphabet_count[26] = {};

    // 입력받은 문자열을 한 번만 순회
    for (auto c : s) {
        alphabet_count[c - 'a']++; // 해당 알파벳의 개수 증가
    }

    // 결과 출력
    for (int i = 0; i < 26; i++) {
        cout << alphabet_count[i] << ' ';
    }

    return 0;
}
*/