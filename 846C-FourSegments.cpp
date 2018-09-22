/*
	SubmissionId	:	30313374
	ContestId	:	846
	Index	:	C
	ProblemName	:	Four Segments
	ProblemTags	:	['brute force', 'dp']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 5010ll
#define INF 1000000010ll

int n, idx1, idx2, idx3, ans1, ans2, ans3;
long long a[MAXN], s[MAXN];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n + 1; i++)
		s[i] = s[i - 1] + a[i - 1];
	long long ans = MAXN * -INF;
	for (int i = 1; i <= n; i++)
	{
		long long mx1 = MAXN * -INF;
		long long mx3 = MAXN * -INF;
		for (int j = 1; j <= i; j++)
		{
			if (s[j] > mx1)
			{
				mx1 = s[j];
				idx1 = j;
			}
		}
		for (int j = i; j <= n + 1; j++)
		{
			if (s[j] > mx3)
			{
				mx3 = s[j];
				idx3 = j;
			}
		}
		if (2 * mx1 - 2 * s[i] + 2 * mx3 - s[n + 1] > ans)
		{
			ans = 2 * mx1 - 2 * s[i] + 2 * mx3 - s[n + 1];
			idx2 = i;
			ans1 = idx1;
			ans2 = idx2;
			ans3 = idx3;
		}
	}
	cout << ans1 - 1 << " " << ans2 - 1 << " " << ans3 - 1 << endl;
	return 0;
}