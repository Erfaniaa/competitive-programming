/*
	SubmissionId	:	19994633
	ContestId	:	707
	Index	:	C
	ProblemName	:	Pythagorean Triples
	ProblemTags	:	['math', 'number theory']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

long long x, y, z;

int main()
{
	cin >> x;
	if (x <= 2)
	{
		cout << -1 << endl;
		return 0;
	}
	if (x % 2 == 0)
	{
		y = (x * x - 4) / 4;
		z = (x * x + 4) / 4;
	}
	else
	{
		y = (x * x - 1) / 2;
		z = (x * x + 1) / 2;
	}
	cout << y << " " << z << endl;
	return 0;
}