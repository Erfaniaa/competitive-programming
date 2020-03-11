/*
	SubmissionId	:	16646400
	ContestId	:	540
	Index	:	D
	ProblemName	:	Bad Luck Island
	ProblemTags	:	['dp', 'probabilities']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

struct Tri
{
	double x, y, z;
	Tri(double _x = 0, double _y = 0, double _z = 0)
	{
		x = _x;
		y = _y;
		z = _z;
	}
};

int r, s, p;
Tri dp[110][110][110];

int main()
{
	cin >> r >> s >> p;
	for (int i = 1; i < 110; i++)
	{
		for (int j = 0; j < 110; j++)
		{
			dp[i][j][0] = Tri(1, 0, 0);
			dp[0][i][j] = Tri(0, 1, 0);
			dp[j][0][i] = Tri(0, 0, 1);
		}
	}
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= s; j++)
			for (int k = 1; k <= p; k++)
			{
				int total = i * j + j * k + k * i;
				dp[i][j][k].x += (i * j) * dp[i][j - 1][k].x / total;
				dp[i][j][k].x += (k * i) * dp[i - 1][j][k].x / total;
				dp[i][j][k].x += (k * j) * dp[i][j][k - 1].x / total;

				dp[i][j][k].y += (j * k) * dp[i][j][k - 1].y / total;
				dp[i][j][k].y += (j * i) * dp[i][j - 1][k].y / total;
				dp[i][j][k].y += (k * i) * dp[i - 1][j][k].y / total;

				dp[i][j][k].z += (k * i) * dp[i - 1][j][k].z / total;
				dp[i][j][k].z += (j * k) * dp[i][j][k - 1].z / total;
				dp[i][j][k].z += (j * i) * dp[i][j - 1][k].z / total;
			}
	cout.precision(10);
	cout << fixed << dp[r][s][p].x << " " << fixed << dp[r][s][p].y << " " << fixed << dp[r][s][p].z << endl;
	return 0;
}