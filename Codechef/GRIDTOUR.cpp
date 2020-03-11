#include <bits/stdc++.h>

using namespace std;

long long gcd(long long x, long long y) {
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

int t;
long long n, m, k;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		if (gcd(n, k) == 1 && gcd(m, k) == 1)
			cout << n * m << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}