#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[9] = { 0 };

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	
	int max = arr[0];
	int num = 0, size = 1;
	for (int i = 0; i < 9; i++) {
		if (arr[i] > max) { max = arr[i]; size = i + 1; }
	}
	cout << max << endl << size;
}