/*
	SubmissionId	:	41190262
	ContestId	:	1016
	Index	:	C
	ProblemName	:	Vasya And The Mushrooms
	ProblemTags	:	['dp', 'implementation']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 300010

long long n;
long long a[3][MAXN], dp1[3][MAXN], dp2[3][MAXN], sum1[MAXN], sum2[MAXN], ans;

int main() {
	cin >> n;
	for (int j = 1; j <= 2; j++)
		for (int i = 1; i <= n; i++)
			cin >> a[j][i];
	for (int i = n; i >= 1; i--)
		sum2[i] = sum2[i + 1] + a[1][i] + a[2][i];
	for (long long i = 1; i <= n; i++)
		if (i % 2 == 1) {
			dp1[1][i] = dp1[1][i - 1] + (2 * i - 2) * a[1][i];
			dp1[2][i] = dp1[1][i] + (2 * i - 1) * a[2][i];
		}
		else
		{
			dp1[2][i] = dp1[2][i - 1] + (2 * i - 2) * a[2][i];	
			dp1[1][i] = dp1[2][i] + (2 * i - 1) * a[1][i];
		}
	dp2[1][n] = (2 * n - 1) * a[1][n] + (2 * n - 2) * a[2][n];
	dp2[2][n] = (2 * n - 2) * a[1][n] + (2 * n - 1) * a[2][n];
	for (long long i = n - 1; i >= 1; i--)
		dp2[1][i] = dp2[1][i + 1] - sum2[i + 1] + (2 * i - 2) * a[2][i] + (2 * n - 1) * a[1][i];
	for (long long i = n - 1; i >= 1; i--)
		dp2[2][i] = dp2[2][i + 1] - sum2[i + 1] + (2 * i - 2) * a[1][i] + (2 * n - 1) * a[2][i];

	for (long long i = 0; i <= n; i++)
		if (i % 2 == 0)
			ans = max(ans, dp1[1][i] + dp2[2][i + 1]);
	for (long long i = 1; i <= n; i++)
		if (i % 2 == 1)
			ans = max(ans, dp1[2][i] + dp2[1][i + 1]);
	cout << ans << endl;
	return 0;
}