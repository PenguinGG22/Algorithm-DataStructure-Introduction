#include<iostream>
using namespace std;

int main() {
	int input , find;
	cin >> input >> find;

	int* arr = new int[input];
	for (int i = 0; i < input; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < input; i++) {
		if (arr[i] < find) cout << arr[i] << " ";
	}
}