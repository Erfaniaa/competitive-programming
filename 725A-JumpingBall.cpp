/*
	SubmissionId	:	22880937
	ContestId	:	725
	Index	:	A
	ProblemName	:	Jumping Ball
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, l, r;
string s;

int main()
{
	cin >> n;
	cin >> s;
	s = "$" + s + "$";
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] != '<')
		{
			l = i - 1;
			break;
		}
	}
	for (int i = s.size() - 2; i >= 0; i--)
	{
		if (s[i] != '>')
		{
			r = s.size() - 2 - i;
			break;
		}
	}
	cout << l + r << endl;
	return 0;
}