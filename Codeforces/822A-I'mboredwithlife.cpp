/*
	SubmissionId	:	28214099
	ContestId	:	822
	Index	:	A
	ProblemName	:	I'm bored with life
	ProblemTags	:	['implementation', 'math', 'number theory']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

long long a, b, ans = 1;

int main()
{
	cin >> a >> b;
	long long k = min(a, b);
	for (long long i = 1; i <= k; i++)
		ans = ans * i;
	cout << ans << endl;
	return 0;
}