/*
	SubmissionId	:	19790521
	ContestId	:	706
	Index	:	B
	ProblemName	:	Interesting drink
	ProblemTags	:	['binary search', 'dp', 'implementation']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int a[MAXN], q, n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	cin >> q;
	while (q--)
	{
		int x;
		cin >> x;
		cout << upper_bound(a, a + n, x) - a << endl;
	}
	return 0;
}