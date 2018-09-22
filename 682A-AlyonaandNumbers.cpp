/*
	SubmissionId	:	18548265
	ContestId	:	682
	Index	:	A
	ProblemName	:	Alyona and Numbers
	ProblemTags	:	['constructive algorithms', 'math', 'number theory']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int m, n;
long long cnt1[10], cnt2[10], ans;

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		cnt1[i % 5]++;
	for (int i = 1; i <= n; i++)
		cnt2[i % 5]++;
	for (int i = 0; i < 5; i++)
		ans += cnt1[i] * cnt2[(5 - i) % 5];
	cout << ans << endl;
	return 0;
}