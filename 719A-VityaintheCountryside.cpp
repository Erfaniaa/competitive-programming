/*
	SubmissionId	:	20840530
	ContestId	:	719
	Index	:	A
	ProblemName	:	Vitya in the Countryside
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[110];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n == 1)
	{
		if (a[n - 1] == 15)
			cout << "DOWN" << endl;
		else if (a[n - 1] == 0)
			cout << "UP" << endl;
		else
			cout << -1 << endl;
		return 0;
	}
	if (a[n - 1] == 15 || (a[n - 1] - a[n - 2] == -1 && a[n - 1] != 0))
		cout << "DOWN" << endl;
	else
		cout << "UP" << endl;
	return 0;
}