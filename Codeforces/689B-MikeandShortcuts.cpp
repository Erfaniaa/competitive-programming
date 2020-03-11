/*
	SubmissionId	:	18923561
	ContestId	:	689
	Index	:	B
	ProblemName	:	Mike and Shortcuts
	ProblemTags	:	['dfs and similar']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define MAXN 200010

int n, dis[MAXN];
vector<int> adj[MAXN];
bool mark[MAXN];

void bfs(int st)
{
	vector<int> q;
	q.push_back(st);
	for (int i = 0; i < q.size(); i++)
	{
		int v = q[i];
		mark[v] = true;
		for (int u: adj[v])
			if (!mark[u])
			{
				mark[u] = true;
				dis[u] = dis[v] + 1;
				q.push_back(u);
			}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		adj[i].push_back(x);
		if (i != n)
		{
			adj[i].push_back(i + 1);
			adj[i + 1].push_back(i);
		}
	}
	bfs(1);
	for (int i = 1; i <= n; i++)
		cout << dis[i] << " ";
	return 0;
}