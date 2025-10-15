#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll recursive(ll A, ll B, ll C) {
	if (B == 1) {
		return A % C;
	}

	ll result = recursive(A, B / 2, C);
	result = (result * result) % C;

	if (B % 2 == 0) {
		return result;
	}
	else {
		return result * A % C;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll A, B, C;
	cin >> A >> B >> C;
	cout << recursive(A, B, C);

	return 0;
}