/*
	SubmissionId	:	19329273
	ContestId	:	701
	Index	:	A
	ProblemName	:	Cards
	ProblemTags	:	['greedy', 'implementation']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[210];
pair<int, int> b[210];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = {a[i], i + 1};
	}
	sort(b, b + n);
	for (int i = 0; i < n / 2; i++)
		cout << b[i].second << " " << b[n - i - 1].second << endl;
	return 0;
}