/*
	SubmissionId	:	19013746
	ContestId	:	690
	Index	:	C2
	ProblemName	:	Brain Network (medium)
	ProblemTags	:	['dfs and similar', 'graphs', 'trees']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int n, m, dis[MAXN];
vector<int> adj[MAXN];

pair<int, int> bfs(int st)
{
	vector<int> q;
	q.clear();
	q.push_back(st);
	memset(dis, -1, sizeof dis);
	dis[st] = 0;
	for (int i = 0; i < q.size(); i++)
	{
		int v = q[i];
		for (int u: adj[v])
			if (dis[u] == -1)
			{
				dis[u] = dis[v] + 1;
				q.push_back(u);
			}
	}
	return {q[q.size() - 1], dis[q[q.size() - 1]]};
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cout << bfs(bfs(1).first).second << endl;
	return 0;
}