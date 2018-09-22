/*
	SubmissionId	:	13437314
	ContestId	:	584
	Index	:	A
	ProblemName	:	Olesya and Rodion
	ProblemTags	:	['math']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <iostream>

using namespace std;

int n, t;

int main()
{
	cin >> n >> t;
	if (n >= 4)
	{
		cout << 5040;
		for (int i = 1; i <= n - 4; i++)
			cout << 0;
		cout << endl;
	}
	if (n == 1)
	{
		if (t == 10)
			cout << -1 << endl;
		else
			cout << t << endl;
	}
	if (n == 2)
	{
		if (t == 10)
			cout << 10 << endl;
		else
			cout << 10 * t << endl;
	}
	if (n == 3)
	{
		if (t == 10)
			cout << 100 << endl;
		else
			cout << 100 * t << endl;	
	}
}