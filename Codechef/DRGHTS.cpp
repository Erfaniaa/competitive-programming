#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <fstream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 100100

int color[MAXN], sum[MAXN], cnt, comp[MAXN], mark[MAXN], start[MAXN], finish[MAXN], n, m;
ll ans1, ans2;
vector<int> adj[MAXN];

inline int count(int v)
{
	return sum[finish[v]] - sum[start[v] - 1];
}

inline void dfs1(int v, int c)
{
	start[v] = ++cnt;
	mark[v] = c;
	comp[c] += color[v];
	FOR (i, 0, SZ(adj[v]) - 1)
	{
		int u = adj[v][i];
		if (!mark[u])
			dfs1(u, c);
	}
	finish[v] = cnt;
}

inline void dfs2(int v, int c)
{
	mark[v] = c;
	int tmp = 0;
	FOR (i, 0, SZ(adj[v]) - 1)
	{
		int u = adj[v][i];
		if (!mark[u])
		{
			if (count(u) >= 1)
				tmp++;
			dfs2(u, c);
		}
	}
	if (color[v] && comp[c] >= 2)
		ans2++;
	else if (count(v) > 0 && count(v) < comp[c])
		ans2++;
	else if (count(v) == comp[c] && tmp >= 2)
		ans2++;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	FOR (i, 1, n)
		cin >> color[i];
	FOR (i, 1, m)
	{
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int c = 0;
	FOR (i, 1, n)
		if (!mark[i])
		{
			c++;
			dfs1(i, c);
			ans1 += (ll)comp[c] * (ll)(comp[c] - 1) / 2;
		}
	FOR (i, 1, n)
		sum[start[i]] = color[i];
	FOR (i, 1, n)
		sum[i] += sum[i - 1];
	memset(mark, 0, sizeof mark);
	c = 0;
	FOR (i, 1, n)
		if (!mark[i])
		{
			c++;
			dfs2(i, c);
		}
	cout << ans1 << " " << ans2 << "\n";
	return 0;
}