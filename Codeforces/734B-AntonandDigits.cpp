/*
	SubmissionId	:	22232950
	ContestId	:	734
	Index	:	B
	ProblemName	:	Anton and Digits
	ProblemTags	:	['implementation', 'math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

long long cnt256, cnt32, a[20];

int main()
{
	cin >> a[2] >> a[3] >> a[5] >> a[6];
	cnt256 = min(a[2], min(a[5], a[6]));
	a[2] -= cnt256;
	a[5] -= cnt256;
	a[6] -= cnt256;
	cnt32 = min(a[2], a[3]);
	cout << cnt256 * 256ll + cnt32 * 32ll << endl;
	return 0;
}