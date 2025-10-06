#include <iostream>
using namespace std;

int main() {
    int input;
    cin >> input;
    
    for (int i = 0; i < input; i++) {
        for (int j = 1; j < input - i; j++) cout << " ";
        for (int j = 1; j < i + 2; j++) cout << "*";
        cout << endl;
    }
}