/*
	SubmissionId	:	22733716
	ContestId	:	742
	Index	:	A
	ProblemName	:	Arpa’s hard exam and Mehrdad’s naive cheat
	ProblemTags	:	['implementation', 'math', 'number theory']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[] = {6, 8, 4, 2};

int main()
{
	cin >> n;
	if (n == 0)
		cout << 1 << endl;
	else
		cout << a[n % 4] << endl;
	return 0;
}