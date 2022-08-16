#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int x, t, dp[MAXN];

int main()
{
	for (int i = 1; i < MAXN; i++)
	{
		dp[i] = i;
		for (int j = 1; j * j * j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j * j] + 1);
	}
	while (cin >> x)
		cout << "Case #" << ++t << ": " << dp[x] << endl;
	return 0;
}