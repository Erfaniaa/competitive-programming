#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int n, m, a[2010], b[2010], c[2010];
long long dp[2010][2010], ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
		dp[i][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 2; j <= m; j++)
			for (int k = j - 1; k < i; k++)
				if (b[j] + a[i] >= b[j - 1] + a[k])
				{
					dp[i][j] += dp[k][j - 1];
					if (dp[i][j] > MOD)
						dp[i][j] -= MOD;
				}
	for (int i = m; i <= n; i++)
	{
		ans += dp[i][m];
		if (ans > MOD)
			ans -= MOD;
	}
	cout << ans << endl;
}