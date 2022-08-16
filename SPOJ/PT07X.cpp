#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
int n, ans, mark[MAXN];
vector <int> adj[MAXN];

void dfs(int x)
{
	mark[x] = 1;
	bool flag = false;
	for (auto y: adj[x])
		if (!mark[y])
		{
			dfs(y);
			if (mark[y] != 2)
				flag = true;
		}
	if (flag)
	{
		ans++;
		mark[x] = 2;
	}
}


int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		if (adj[i].size() > 1)
		{
			dfs(i);
			break;
		}
	if (n == 1)
		cout << 0 << endl;
	else if (n == 2)
		cout << 1 << endl;
	else
		cout << ans << endl;
	return 0;
}