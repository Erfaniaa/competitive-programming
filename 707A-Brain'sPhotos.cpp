/*
	SubmissionId	:	19995587
	ContestId	:	707
	Index	:	A
	ProblemName	:	Brain's Photos
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	bool flag = false;
	for (int i = 0; i < n * m; i++)
	{
		char ch;
		cin >> ch;
		if (ch != 'B' && ch != 'W' && ch != 'G')
			flag = true;
	}
	if (flag)
		cout << "#Color" << endl;
	else
		cout << "#Black&White" << endl;
	return 0;
}