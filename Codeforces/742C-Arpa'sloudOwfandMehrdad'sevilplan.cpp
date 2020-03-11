/*
	SubmissionId	:	22801593
	ContestId	:	742
	Index	:	C
	ProblemName	:	Arpa's loud Owf and Mehrdad's evil plan
	ProblemTags	:	['dfs and similar', 'math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[250];
long long ans = 1;

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

void dfs(int start, int v, int depth)
{
	if (depth > 220 || ans == -1)
	{
		ans = -1;
		return;
	}
	if (a[v] == start)
	{
		if (depth % 2 == 0)
			depth /= 2;
		ans = (ans * depth) / gcd(ans, depth);
		return;
	}
	dfs(start, a[v], depth + 1);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		dfs(i, i, 1);
	cout << ans << endl;
	return 0;
}