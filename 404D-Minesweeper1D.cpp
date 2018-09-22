/*
	SubmissionId	:	13410964
	ContestId	:	404
	Index	:	D
	ProblemName	:	Minesweeper 1D
	ProblemTags	:	['dp', 'implementation']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

long long dp[1000010][2];
string s;

int main()
{
	cin >> s;
	s = '?' + s;
	int len = (int)s.size();
	dp[0][0] = 1;
	for (int i = 1; i < len; i++)
	{
		if (s[i] == '?')
		{
			if (s[i - 1] == '?')
			{
				dp[i][0] = dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
			}
			else if (s[i - 1] == '0')
			{
				dp[i][0] = dp[i - 1][0];
			}
			else if (s[i - 1] == '1')
			{
				dp[i][0] = dp[i - 2][1];
				dp[i][1] = dp[i - 2][0];
			}
			else if (s[i - 1] == '2')
			{
				dp[i][1] = dp[i - 2][1];
			}
			else if (s[i - 1] == '*')
			{
				dp[i][0] = dp[i][1] = dp[i - 1][1];
			}
		}
		else if (s[i] == '*')
		{
			if (s[i - 1] == '?')
			{
				dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
			}
			else if (s[i - 1] == '0')
			{
				
			}
			else if (s[i - 1] == '1')
			{
				dp[i][1] = dp[i - 2][0];
			}
			else if (s[i - 1] == '2')
			{
				dp[i][1] = dp[i - 2][1];
			}
			else if (s[i - 1] == '*')
			{
				dp[i][1] = dp[i - 1][1];
			}
		}
		else
		{
			if (s[i] == '0')
			{
				dp[i][0] = dp[i - 1][0];
			}
			else if (s[i] == '1')
			{
				//if (i != len - 1)
				//	dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
				//else
					dp[i][0] = dp[i - 1][1];
			}
			else if (s[i] == '2')
			{
				//if (i != len - 1)
				//	dp[i][0] = dp[i - 1][1];
			}
		}
		//cout << i << ": " <<  dp[i][0] << " - " << dp[i][1] << endl;
	}
	cout << (dp[len - 1][0] + dp[len - 1][1]) % MOD << endl;
	return 0;
}