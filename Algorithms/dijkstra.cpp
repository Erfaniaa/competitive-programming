#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
const int INF = 1000000010;

int d[MAXN], n, m;
vector<pair<int, int> > adj[MAXN];

int dijkstra(int s, int t)
{
	set<pair<int, int> > q;
	for (int i = 1; i <= n; i++)
		d[i] = INF;
	d[s] = 0;
	q.insert(make_pair(0, s));
	while ((int)q.size())
	{
		pair<int, int> v = *(q.begin());
		q.erase(v);
		for (int i = 0; i < adj[v.second].size(); i++)
		{
			pair<int, int> u = adj[v.second][i];
			if (d[v.second] + u.second < d[u.first])
			{
				q.erase(make_pair(d[u.first], u.first));
				d[u.first] = d[v.second] + u.second;
				q.insert(make_pair(d[u.first], u.first));
			}
		}
	}
	return d[t];
}

int prim(int s)
{
	set<pair<int, int> > q;
	for (int i = 1; i <= n; i++)
		d[i] = INF;
	d[s] = 0;
	q.insert(make_pair(0, s));
	int ret = 0;
	while ((int)q.size())
	{
		pair<int, int> v = *(q.begin());
		ret += v.first;
		q.erase(v);
		for (int i = 0; i < adj[v.second].size(); i++)
		{
			pair<int, int> u = adj[v.second][i];
			if (u.second < d[u.first])
			{
				q.erase(make_pair(d[u.first], u.first));
				d[u.first] = u.second;
				q.insert(make_pair(d[u.first], u.first));
			}
		}
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back(make_pair(y, w));
		adj[y].push_back(make_pair(x, w));
	}
	cout << dijkstra(1, n) << endl;
	cout << prim(1) << endl;
	return 0;
}

/*

5 7
1 2 2
2 3 2
3 4 2
4 5 2
1 3 3
3 5 3
1 5 1

*/