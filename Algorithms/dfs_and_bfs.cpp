#include <bits/stdc++.h>

using namespace std;

int n, m, cnt, mark[1010];
vector<int> adj[1010];

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

void bfs(int st)
{
	memset(dis, -1, sizeof dis);
	dis[st] = 0;
	vector<int> q;
	q.push_back(st);
	for (int i = 0; i < q.size(); i++)
	{
		int v = q[i];
		for (int j = 0; j < adj[v]; j++)
		{
			int u = adj[v][j];
			if (dis[u] != -1)
			{
				dis[u] = dis[v] + 1;
				q.push_back(u);
			}
		}
	} 
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		if (!mark[i])
		{
			cnt++;
			dfs(i);
		}
	return 0;
}