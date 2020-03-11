#include <bits/stdc++.h>

using namespace std;

int t, n, k, a[10010];

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		long long sum = 0;
		for (int i = k; i < n - k; i++)
			sum += a[i];
		cout.precision(6);
		cout << fixed << (double)sum / (n - 2 * k) << endl;
	}
	return 0;
}