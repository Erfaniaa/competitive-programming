/*
	SubmissionId	:	22230902
	ContestId	:	734
	Index	:	A
	ProblemName	:	Anton and Danik
	ProblemTags	:	['implementation', 'strings']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, cnt[300];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char ch;
		cin >> ch;
		cnt[ch]++;
	}
	if (cnt['A'] > cnt['D'])
		cout << "Anton" << endl;
	if (cnt['A'] < cnt['D'])
		cout << "Danik" << endl;
	if (cnt['A'] == cnt['D'])
		cout << "Friendship" << endl;
	return 0;
}