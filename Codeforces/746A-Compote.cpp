/*
	SubmissionId	:	23082305
	ContestId	:	746
	Index	:	A
	ProblemName	:	Compote
	ProblemTags	:	['math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main()
{
	cin >> a >> b >> c;
	int cnt = min(a, min(b / 2, c / 4));
	cout << cnt * 7 << endl;
}