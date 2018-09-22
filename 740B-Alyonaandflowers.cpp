/*
	SubmissionId	:	22446968
	ContestId	:	740
	Index	:	B
	ProblemName	:	Alyona and flowers
	ProblemTags	:	['constructive algorithms']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, a[210], ans;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
	{
		int x, y, sum = 0;
		cin >> x >> y;
		for (int j = x; j <= y; j++)
			sum += a[j];
		if (sum > 0)
			ans += sum;
	}
	cout << ans << endl;
	return 0;
}