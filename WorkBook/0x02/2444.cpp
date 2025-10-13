#include <iostream>
using namespace std;

int main(){
    int input;
    cin >> input;
    for(int i=1; i<input; i++){
        for(int j=0; j<input-i; j++) cout <<' ';
        for(int j=0; j<2*i-1; j++) cout <<'*';
        cout << endl;
    }
    for(int i=input; i>0; i--){
        for(int j=0; j<input-i; j++) cout <<' ';
        for(int j=0; j<2*i-1; j++) cout <<'*';
        cout << endl;
    }
}