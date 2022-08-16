#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define MAXN 100010

int n, m, backEdge[MAXN], dis[MAXN], color[MAXN], cnt, mark[MAXN];
vector<int> adj[MAXN], st, comp[MAXN], ans;

int dfs(int v, int d)
{
	mark[v] = 1;
	dis[v] = d;
	if (backEdge[v] != MAXN)
		return backEdge[v];
	backEdge[v] = d;
	st.push_back(v);
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (mark[u] == 1)
			backEdge[v] = min(backEdge[v], dis[u]);
		if (!mark[u])
			backEdge[v] = min(backEdge[v], dfs(u, d + 1));
		if (mark[u] == 2 && color[u] == 0)
			backEdge[v] = min(backEdge[v], backEdge[u]);
	}
	mark[v] = 2;
	if (backEdge[v] == d)
	{
		cnt++;
		while (st[st.size() - 1] != v)
		{
			int a = st[st.size() - 1];
			comp[cnt].push_back(a);
			color[a] = cnt;
			st.pop_back();
		}
		comp[cnt].push_back(v);
		color[v] = cnt;
		st.pop_back();
	}
	return backEdge[v];
}

int main()
{
	while (cin >> n)
	{
		if (n == 0)
			return 0;
		cin >> m;
		for (int i = 1; i <= n; i++)
			adj[i].clear();
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		for (int i = 1; i <= n; i++)
		{
			backEdge[i] = MAXN;
			mark[i] = 0;
			comp[i].clear();
			color[i] = 0;
		}
		ans.clear();
		cnt = 0;
		st.clear();
		for (int i = 1; i <= n; i++)
			if (!mark[i])
				dfs(i, 1);
		for (int i = 1; i <= cnt; i++)
		{
			bool correct = true;
			for (int j = 0; j < comp[i].size(); j++)
			{
				int v = comp[i][j];
				for (int k = 0; k < adj[v].size(); k++)
					if (color[adj[v][k]] != i)
					{
						correct = false;
						break;
					}
				if (!correct)
					break;
			}	
			if (correct)
				for (int j = 0; j < comp[i].size(); j++)
					ans.push_back(comp[i][j]);
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
		/*cout << "Count: " << cnt << endl;
		for (int i = 1; i <= cnt; i++)
		{
			for (int j = 0; j < comp[i].size(); j++)
				cout << comp[i][j] << " ";
			cout << endl;
		}*/
//		cin >> n;
	}
	return 0;
}
