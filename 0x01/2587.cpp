#include<iostream>
using namespace std;

int main() {
	int arr[5] = { 0, };
	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5 - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	cout << sum / 5 << endl << arr[2];
	return 0;
}