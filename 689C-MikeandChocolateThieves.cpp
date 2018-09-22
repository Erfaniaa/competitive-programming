/*
	SubmissionId	:	18927867
	ContestId	:	689
	Index	:	C
	ProblemName	:	Mike and Chocolate Thieves
	ProblemTags	:	['binary search', 'math']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

long long f(long long t)
{
	long long ret = 0;
	for (long long i = 2; i <= t; i++)
	{
		long long tmp = t / (i * i * i);
		if (tmp == 0)
			break;
		ret += tmp;
	}
	return ret;
}

long long m, l, r, ans = -1;

int main()
{
	l = 0;
	r = 1000000ll * 1000000ll * 1000000ll;
	cin >> m;
	while (l <= r)
	{
		long long mid = (l + r) / 2;
		if (f(mid) < m)
			l = mid + 1;
		else
		{
			r = mid - 1;
			ans = mid;
		}
	}
	if (ans != -1 && f(ans) == m)
		cout << ans << endl;
	else
		cout << -1 << endl;
	return 0;
}