#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300010;

int n, m, k;
vector<int> specials, adj[MAXN], wei[MAXN];
bool isSpecial[MAXN];
long long dis[MAXN];
set<pair<long long, int> > st;

inline long long dijkstra(int s)
{
	for (int i = 1; i <= n; i++)
		dis[i] = (long long)MAXN * MAXN;
	dis[s] = 0;
	st.clear();
	st.insert(make_pair(0, s));
	while (st.size())
	{
		pair<long long, int> v = *(st.begin());
		if (isSpecial[v.second] && v.second != s)
			return v.first;
		for (int i = 0; i < adj[v.second].size(); i++)
		{
			int u = adj[v.second][i];
			int w = wei[v.second][i];
			if (v.first + w < dis[u])
			{
				st.erase(make_pair(dis[u], u));
				dis[u] = v.first + w;
				st.insert(make_pair(dis[u], u));
			}
		}
		st.erase(v);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		specials.push_back(x);
		isSpecial[x] = true;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back(y);
		wei[x].push_back(w);
		adj[y].push_back(x);
		wei[y].push_back(w);
	}
	long long ans = (long long)MAXN * MAXN;
	for (int i = 0; i < k - 1; i++)
		ans = min(ans, dijkstra(specials[i]));
	cout << ans << endl;
	return 0;
}