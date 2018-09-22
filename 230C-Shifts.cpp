/*
	SubmissionId	:	6818325
	ContestId	:	230
	Index	:	C
	ProblemName	:	Shifts
	ProblemTags	:	['binary search', 'data structures', 'dp', 'implementation']
	ProgrammingLanguage	:	GNU C++0x
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 105

int dp[MAXN][MAXN * MAXN][3], ans, n, m;
char a[MAXN][MAXN * MAXN];

int calc(int x, int y, int dir)
{
	if (y == 0)
		y = m;
	else if (y == m + 1)
		y = 1;
	if (a[x][y] == '1')
		return dp[x][y][dir + 1] = 0;
	else
	{
		if (dp[x][y][dir + 1])
			return dp[x][y][dir + 1];
		else
			return dp[x][y][dir + 1] = (calc(x, y + dir, dir) + 1);
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		bool flag = false;
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == '1')
				flag = true;
		}
		if (!flag)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	ans = 1000 * 1000 * 1000;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)		
		{
			calc(i, j, -1);
			calc(i, j, +1);
		}
	for (int j = 1; j <= m; j++)
	{
		int tmp = 0;
		for (int i = 1; i <= n; i++)
			tmp += min(dp[i][j][0], dp[i][j][2]);
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}