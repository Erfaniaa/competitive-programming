/*
	SubmissionId	:	19788191
	ContestId	:	706
	Index	:	A
	ProblemName	:	Beru-taxi
	ProblemTags	:	['brute force', 'geometry', 'implementation']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int a, b, n;

int main()
{
	cin >> a >> b;
	cin >> n;
	double ans = 1000000;
	for (int i = 1; i <= n; i++)
	{
		int x, y, v;
		cin >> x >> y >> v;
		ans = min(ans, hypot(x - a, y - b) / v);
	}
	cout.precision(7);
	cout << fixed << ans << endl;
	return 0;
}