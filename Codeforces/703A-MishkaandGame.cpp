/*
	SubmissionId	:	19618555
	ContestId	:	703
	Index	:	A
	ProblemName	:	Mishka and Game
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, cnt1, cnt2;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		cnt1 += a > b;
		cnt2 += a < b;
	}
	if (cnt1 > cnt2)
		cout << "Mishka" << endl;
	if (cnt1 == cnt2)
		cout << "Friendship is magic!^^" << endl;
	if (cnt1 < cnt2)
		cout << "Chris" << endl;
	return 0;
}