/*
	SubmissionId	:	14897590
	ContestId	:	605
	Index	:	A
	ProblemName	:	Sorting Railway Cars
	ProblemTags	:	['constructive algorithms', 'greedy']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <iostream>

using namespace std;

#define MAXN 100010
int n, a[MAXN], p[MAXN], dp[MAXN], ans;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		p[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > 1 && i > p[a[i] - 1])
			dp[i] = dp[p[a[i] - 1]] + 1;
		else
			dp[i] = 1;
		ans = max(ans, dp[i]);
	}
	cout << n - ans << endl;
	return 0;
}