/*
	SubmissionId	:	39553696
	ContestId	:	991
	Index	:	A
	ProblemName	:	If at first you don't succeed...
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int a, b, c, n;

int main() {
	cin >> a >> b >> c >> n;
	int tmp = n - (a + b - c);
	if (tmp <= 0 || c > a || c > b)
		cout << -1 << endl;
	else
		cout << tmp << endl;
}