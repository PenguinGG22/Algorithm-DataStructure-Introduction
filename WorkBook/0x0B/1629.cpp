#include <bits/stdc++.h>
using namespace std;

long long result = 1;

long long recursive(long long A, long long B, long long C) {
	if (B <= 1) return A % C;

	long long tmp = recursive(A, B / 2, C);
	result = (tmp * tmp) % C;
	
	if (B % 2 != 0)result = (result * A) % C;
	
	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long A, B, C;
	cin >> A >> B >> C;

	cout << recursive(A, B, C);

	return 0;
}