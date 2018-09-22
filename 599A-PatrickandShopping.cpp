/*
	SubmissionId	:	14400375
	ContestId	:	599
	Index	:	A
	ProblemName	:	Patrick and Shopping
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <iostream>

using namespace std;

int main()
{
	int d1, d2, d3;
	cin >> d1 >> d2 >> d3;
	cout << min(min(d1 + d2 + d3, 2 * (d1 + d2)), min(2 * (d1 + d3), 2 * (d2 + d3))) << endl;
	return 0;
}