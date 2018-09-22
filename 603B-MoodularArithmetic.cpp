/*
	SubmissionId	:	14909035
	ContestId	:	603
	Index	:	B
	ProblemName	:	Moodular Arithmetic
	ProblemTags	:	['dfs and similar', 'dsu', 'math', 'number theory']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1000010];
bool mark[1000010];
long long p, k;

void dfs(int v)
{
	mark[v] = true;
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (!mark[u])
			dfs(u);
	}
}

int main()
{
	cin >> p >> k;
	long long ans = 1;
	if (k == 0)
	{
		for (int i = 1; i <= p - 1; i++)
			ans = (ans * p) % 1000000007ll;
		cout << ans << endl;
		return 0;
	}
	if (k == 1)
	{
		for (int i = 1; i <= p; i++)
			ans = (ans * p) % 1000000007ll;
		cout << ans << endl;
		return 0;
	}
	for (int i = 0; i < p; i++)
	{
		int j = (k * i) % p;
		adj[i].push_back(j);
		if (i != j)
			adj[j].push_back(i);
	}
	for (int i = 1; i < p; i++)
		if (!mark[i])
		{
			dfs(i);
			ans = (ans * p) % (1000000007ll);
		}
	cout << ans << endl;
	return 0;
}