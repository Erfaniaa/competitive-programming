/*
	SubmissionId	:	18549742
	ContestId	:	682
	Index	:	B
	ProblemName	:	Alyona and Mex
	ProblemTags	:	['sortings']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, ans, a[100010];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > ans)
			ans++;
	cout << ans + 1 << endl;
	return 0;
}