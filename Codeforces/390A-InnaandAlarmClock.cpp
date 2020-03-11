/*
	SubmissionId	:	22119384
	ContestId	:	390
	Index	:	A
	ProblemName	:	Inna and Alarm Clock
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n;
set<int> setX, setY;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		setX.insert(x);
		setY.insert(y);
	}
	cout << min(setX.size(), setY.size()) << endl;
	return 0;
}