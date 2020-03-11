/*
	SubmissionId	:	19583140
	ContestId	:	698
	Index	:	A
	ProblemName	:	Vacations
	ProblemTags	:	['dp']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[210], dp[210][4];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	dp[0][0] = (a[0] == 0) ? 1 : 1000000;
	dp[0][1] = (a[0] & 1) ? 0 : 1000000;
	dp[0][2] = (a[0] & 2) ? 0 : 1000000;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= 2; j++)
			dp[i][j] = 1000000;
		if (a[i] == 0)
			dp[i][0] = 1 + min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
		else
		{
			dp[i][0] = 1 + min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
			for (int j = 1; j <= 2; j++)
			{
				if (j & a[i])
				{
					dp[i][j] = dp[i - 1][0];
					for (int k = 1; k <= 2; k++)
						if (j != k)
							dp[i][j] = min(dp[i][j], dp[i - 1][k]);
				}
			}
		}
	}
	cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
	return 0;
}