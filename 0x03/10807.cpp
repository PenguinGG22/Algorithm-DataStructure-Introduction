#include<iostream>
using namespace std;

int main() {
	int input;
	cin >> input;

	int* arr = new int[input];
	for (int i = 0; i < input; i++) {
		cin >> arr[i];
	}
	
	int find;
	int cnt = 0;
	cin >> find;
	for (int i = 0; i < input; i++) {
		if (arr[i] == find) cnt++;
	}
	cout << cnt;
}