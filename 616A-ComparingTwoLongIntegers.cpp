/*
	SubmissionId	:	16616082
	ContestId	:	616
	Index	:	A
	ProblemName	:	Comparing Two Long Integers
	ProblemTags	:	['implementation', 'strings']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	if (s1.length() < s2.length())
		s1 = string(s2.length() - s1.length(), '0') + s1;
	else
		s2 = string(s1.length() - s2.length(), '0') + s2;
	if (s1 < s2)
		cout << "<" << endl;
	if (s1 == s2)
		cout << "=" << endl;
	if (s1 > s2)
		cout << ">" << endl;
}