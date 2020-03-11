/*
	SubmissionId	:	14900197
	ContestId	:	609
	Index	:	B
	ProblemName	:	The Best Gift
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <iostream>

using namespace std;

int n, m, cnt[100010];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		cnt[x]++;
	}
	long long ans = (long long)n * (long long)(n - 1) / 2;
	for (int i = 1; i <= m; i++)
		ans -= (long long)cnt[i] * (long long)(cnt[i] - 1) / 2;
	cout << ans << endl;
	return 0;
}