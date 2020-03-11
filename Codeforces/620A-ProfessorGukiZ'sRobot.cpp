/*
	SubmissionId	:	18370464
	ContestId	:	620
	Index	:	A
	ProblemName	:	Professor GukiZ's Robot
	ProblemTags	:	['implementation', 'math']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x1, x2, y1, y2;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cout << max(abs(x1 - x2), abs(y1 - y2)) << endl; 
	return 0;
}