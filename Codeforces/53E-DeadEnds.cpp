/*
	SubmissionId	:	6818061
	ContestId	:	53
	Index	:	E
	ProblemName	:	Dead Ends
	ProblemTags	:	['bitmasks', 'dp']
	ProgrammingLanguage	:	GNU C++0x
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, k, maxMask, dp[1 << 11][1 << 11], mat[11][11], ans;

int main()
{
	cin >> n >> m >> k;
	maxMask = 1 << n;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		mat[x][y] = mat[y][x] = 1;
	}
	dp[0][0] = 1;
	for (int nodes = 0; nodes < maxMask; nodes++)
	{
		if (__builtin_popcount(nodes) == 1)
			dp[nodes][0] = 1;
		if (__builtin_popcount(nodes) == 2)
		{
			int t = nodes;
			int v = __builtin_ctz(t);
			t -= 1 << v;
			int u = __builtin_ctz(t);
			dp[nodes][nodes] = mat[u][v];
		}
	}
	for (int nodes = 1; nodes < maxMask; nodes++)
	{
		for (int leaves = 1; leaves < maxMask; leaves++)
		{
			if ((__builtin_popcount(nodes) > 2) && ((nodes | leaves) == nodes))
			{
				int v = 11;
				for (;;v--)
					if (leaves & (1 << v))
						break;
				for (int u = 0; u <= n - 1; u++)
					if (mat[v][u] && (nodes & (1 << u)) && !(leaves & (1 << u)))
						dp[nodes][leaves] += dp[nodes - (1 << v)][leaves - (1 << v)] + dp[nodes - (1 << v)][leaves - (1 << v) + (1 << u)];
			}
			if (__builtin_popcount(nodes) == n && __builtin_popcount(leaves) == k)
				ans += dp[nodes][leaves];
		}
	}
	cout << ans << endl;
	return 0;
}