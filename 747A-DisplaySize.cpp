/*
	SubmissionId	:	23118119
	ContestId	:	747
	Index	:	A
	ProblemName	:	Display Size
	ProblemTags	:	['brute force', 'math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, ans = 1;

int main()
{
	cin >> n;
	for (int i = 1; i * i <= n; i++)
		if (n % i == 0)
			ans = i;
	cout << ans << " " << n / ans << endl;
	return 0;
}