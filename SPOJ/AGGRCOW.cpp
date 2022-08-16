#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int t, n, m, x[MAXN], ans;

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> x[i];
		sort(x, x + n);
		int l = 0, r = 2000000000;
		while (r >= l)
		{
			int mid = (l + r) / 2;
			int sum = 0, last = 0, cnt = 1;
			for (int i = 1; i < n; i++)
			{
				sum = x[i] - x[last];
				if (sum >= mid)
				{
					sum = 0;
					last = i;
					cnt++;
				}
			}
			if (cnt >= m)
			{
				ans = mid;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		cout << ans << endl;
	}
	return 0;
}