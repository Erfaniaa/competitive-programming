/*
	SubmissionId	:	33128120
	ContestId	:	900
	Index	:	C
	ProblemName	:	Remove Extra One
	ProblemTags	:	['brute force', 'data structures', 'math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int n, a[MAXN], mx1 = -MAXN, mx2 = -MAXN - 10, ans = 1, cnt[MAXN];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > mx1)
		{
			mx2 = mx1;
			mx1 = a[i];
			cnt[a[i]]--;
		}
		else if (a[i] > mx2)
		{
			mx2 = a[i];
			cnt[mx1]++;
		}
	}
	for (int i = 1; i <= n; i++)
		if (cnt[i] > cnt[ans])
			ans = i;
	cout << ans << endl;
	return 0;
}