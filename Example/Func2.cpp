bool func2(int arr[], int N) {
	bool hap[101] = { false };
	for (int i = 0; i < N; i++) {
		if (hap[100 - arr[i]] == true) return 1;
		hap[arr[i]] = true;
	}
	return 0;
}