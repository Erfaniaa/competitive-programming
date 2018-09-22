/*
	SubmissionId	:	16616200
	ContestId	:	616
	Index	:	B
	ProblemName	:	Dinner with Emma
	ProblemTags	:	['games', 'greedy']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, a[110][110], mn[110];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
	{
		mn[i] = 1000 * 1000 * 1000 + 1;
		for (int j = 0; j < m; j++)
			mn[i] = min(mn[i], a[i][j]);
	}
	cout << *max_element(mn, mn + n) << endl;
}