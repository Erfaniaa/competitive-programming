/*
	SubmissionId	:	21404297
	ContestId	:	723
	Index	:	A
	ProblemName	:	The New Year: Meeting Friends
	ProblemTags	:	['sortings']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int a[10];

int main()
{
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	cout << a[2] - a[0] << endl;
	return 0;
}