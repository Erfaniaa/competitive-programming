/*
	SubmissionId	:	14763219
	ContestId	:	598
	Index	:	E
	ProblemName	:	Chocolate Bar
	ProblemTags	:	['brute force', 'dp']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <iostream>

using namespace std;

int dp[31][31][30 * 30 + 10];

int main()
{
	int t;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	for (int n = 1; n <= 30; n++)
		for (int m = 1; m <= 30; m++)
			for (int k = 1; k <= 30 * 30; k++)
				dp[m][n][k] = 1000000000;
	for (int n = 1; n <= 30; n++)
	{
		for (int m = 1; m <= 30; m++)
			for (int k = 1; k <= m * n; k++)
			{
				if (k == n * m)
					dp[n][m][k] = 0;
				else
				{
					for (int i = 1; i < n; i++)
					{
						dp[n][m][k] = min(dp[n - i][m][k] + m * m, dp[n][m][k]);
						if (k - i * m >= 0)
							dp[n][m][k] = min(dp[n - i][m][k - i * m] + m * m, dp[n][m][k]);
					}
					for (int i = 1; i < m; i++)
					{
						dp[n][m][k] = min(dp[n][m - i][k] + n * n, dp[n][m][k]);
						if (k - i * n >= 0)
							dp[n][m][k] = min(dp[n][m - i][k - i * n] + n * n, dp[n][m][k]);
					}
				}
			}
	}
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		cout << dp[n][m][k] << endl;
	}
	return 0;
}