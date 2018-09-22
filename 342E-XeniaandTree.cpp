/*
	SubmissionId	:	5415308
	ContestId	:	342
	Index	:	E
	ProblemName	:	Xenia and Tree
	ProblemTags	:	['data structures', 'divide and conquer', 'trees']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>

using namespace std;

#define pb push_back
#define SZ(x) ((int)((x).size()))
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010
#define MAXLOGN 18

vector<int> adj[MAXN], reds;
int level[MAXN], p[MAXN][MAXLOGN + 1], dis[MAXN], n, m, b;
bool mark[MAXN];

inline void dfs(int v, int f, int d)
{
	dis[v] = level[v] = d;
	p[v][0] = f;
	FOR (i, 1, MAXLOGN)
		if (p[v][i - 1] == -1)
			p[v][i] = -1;
		else
			p[v][i] = p[p[v][i - 1]][i - 1];
	FOR (i, 0, SZ(adj[v]) - 1)
	{
		int u = adj[v][i];
		if (u != f)
			dfs(u, v, d + 1);
	}
}

inline int parent(int v, int k)
{
	FOR (i, 0, MAXLOGN)
	{
		if (k % 2)
			v = p[v][i];
		k /= 2;
	}
	return v;
}

int lca(int v, int u)
{
	if (level[v] < level[u])
		swap(u, v);
	v = parent(v, level[v] - level[u]);
	if (v == u)
		return v;
	FORD (i, MAXLOGN, 0)
		if (p[v][i] != p[u][i])
		{
			v = p[v][i];
			u = p[u][i];
		}
	return p[v][0];
}

inline void bfs()
{
	vector<int> q;
	memset(mark, 0, sizeof mark);
	FOR (i, 0, SZ(reds) - 1)
	{
		mark[reds[i]] = true;
		q.pb(reds[i]);
		dis[reds[i]] = 0;
	}
	FOR (i, 0, SZ(q) - 1)
	{
		int v = q[i];
		mark[v] = true;
		FOR (j, 0, SZ(adj[v]) - 1)
		{
			int u = adj[v][j];
			if (!mark[u])
			{
				mark[u] = true;
				if (dis[v] + 1 < dis[u])
					dis[u] = dis[v] + 1;
				q.pb(u);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int b = sqrt(m);
	FOR (i, 1, n - 1)
	{
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, -1, 0);
	reds.pb(1);
	FOR (i, 1, m)
	{
		if (SZ(reds) >= b)
		{
			bfs();
			reds.clear();
		}
		int q, v;
		cin >> q >> v;
		if (q == 1)
			reds.pb(v);
		else
		{
			int ans = dis[v];
			FOR (j, 0, SZ(reds) - 1)
			{
				int u = reds[j];
				int tmp = level[v] + level[u] - 2 * level[lca(v, u)];
				if (tmp < ans)
					ans = tmp;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}