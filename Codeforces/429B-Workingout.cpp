/*
	SubmissionId	:	6592967
	ContestId	:	429
	Index	:	B
	ProblemName	:	Working out
	ProblemTags	:	['dp']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF (1000 * 1000 * 1000)
#define MAXN 1010

int n, m;
long long a[MAXN][MAXN], dp[5][MAXN][MAXN], ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[1][i][j] = a[i][j] + max(dp[1][i - 1][j], dp[1][i][j - 1]);
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 1; j--)
			dp[2][i][j] = a[i][j] + max(dp[2][i - 1][j], dp[2][i][j + 1]);
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= m; j++)
			dp[3][i][j] = a[i][j] + max(dp[3][i + 1][j], dp[3][i][j - 1]);
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
			dp[4][i][j] = a[i][j] + max(dp[4][i + 1][j], dp[4][i][j + 1]);
	for (int i = 2; i <= n - 1; i++)
		for (int j = 2; j <= m - 1; j++)
		{
			long long temp;
			temp = dp[1][i][j - 1] + dp[3][i + 1][j] + dp[2][i - 1][j] + dp[4][i][j + 1];
			temp = max(temp, dp[1][i - 1][j] + dp[3][i][j - 1] + dp[2][i][j + 1] + dp[4][i + 1][j]);
			ans = max(ans, temp);
		}
	cout << ans << endl;
	return 0;
}