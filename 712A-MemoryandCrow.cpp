/*
	SubmissionId	:	20503400
	ContestId	:	712
	Index	:	A
	ProblemName	:	Memory and Crow
	ProblemTags	:	['implementation', 'math']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int n, a[MAXN];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cout << a[i] + a[i + 1] << " ";
	return 0;
}