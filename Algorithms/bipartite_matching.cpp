#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200010;
int part1, part2, m;
vector<int> adj[MAXN];
bool mark[MAXN];

int match[MAXN], ans;

int dfs(int v)
{
	mark[v] = true;
	for (int i = 0; i < (int)adj[v].size(); i++)
	{
		int w = adj[v][i];
		if (mark[match[w]])
			continue;
		if (!match[w] || dfs(match[w]))
		{
			match[w] = v;
			return 1;
		}
	}
	return 0;
}

void addEdge(int x, int y)
{
	adj[x].push_back(y + part1);
	adj[y + part1].push_back(x);
}

int main()
{
	cin >> part1 >> part2 >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		addEdge(x, y);
	}
	for (int i = 1; i <= part1; i++)
	{
		memset(mark, 0, sizeof mark);
		if (!mark[i])
			ans += dfs(i);
	}
	cout << ans << endl;
	for (int i = part1 + 1; i <= part1 + part2; i++)
		cout << i - part1 << ": " << match[i] << endl;
	return 0;
}

/*

2 2 3
1 1
1 2
2 1

*/

/*

3 3 5
1 1
1 2
2 1 
2 3
3 1

*/