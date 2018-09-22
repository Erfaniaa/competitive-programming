/*
	SubmissionId	:	5758346
	ContestId	:	384
	Index	:	E
	ProblemName	:	Propagating tree
	ProblemTags	:	['data structures', 'dfs and similar', 'graphs', 'trees']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<fstream>
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
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 200010

int start[MAXN], finish[MAXN], cnt, n, m, a[MAXN], dis[MAXN];
ll tree[2][8 * MAXN];
vector<int> adj[MAXN], nodes[2], starts[2];

inline void update(int v, int vl, int vr, int l, int r, int val, int k)
{
	int mid = (vl + vr) / 2;
	if (l <= vl && vr <= r)
	{
		tree[k][v] += val;
		return;
	}
	if (vr < l || r < vl)
		return;
	update(2 * v, vl, mid, l, r, val, k);
	update(2 * v + 1, mid + 1, vr, l, r, val, k);
}

inline ll getVal(int v, int vl, int vr, int idx, int k)
{
	int mid = (vl + vr) / 2;
	if (vl == vr)
		return tree[k][v];
	if (idx <= mid)
		return tree[k][v] + getVal(2 * v, vl, mid, idx, k);
	else
		return tree[k][v] + getVal(2 * v + 1, mid + 1, vr, idx, k);
}

inline void dfs(int v, int f, int d)
{
	cnt++;
	start[v] = cnt;
	nodes[d % 2].pb(v);
	starts[d % 2].pb(start[v]);
	dis[v] = d % 2;
	FOR (i, 0, SZ(adj[v]) - 1)
		if (adj[v][i] != f)
			dfs(adj[v][i], v, d + 1);
	finish[v] = cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	FOR (i, 1, n)
		cin >> a[i];
	FOR (i, 1, n - 1)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, -1, 0);
	FOR (i, 1, n)
	{
		int k = dis[i];
		int idx = lower_bound(ALL(starts[k]), start[i]) - starts[k].begin();
		idx++;
		update(1, 1, n, idx, idx, a[i], k);
	}
	starts[0].pb(INF);
	starts[1].pb(INF);
	FOR (i, 1, m)
	{
		int q, x, v;
		cin >> q;
		if (q == 1)
		{
			cin >> x >> v;
			int k = dis[x];
			int idx1 = lower_bound(ALL(starts[k]), start[x]) - starts[k].begin();
			int idx2 = lower_bound(ALL(starts[k]), finish[x]) - starts[k].begin();
			int idx3 = lower_bound(ALL(starts[1 - k]), start[x]) - starts[1 - k].begin();
			int idx4 = lower_bound(ALL(starts[1 - k]), finish[x]) - starts[1 - k].begin();
			if (idx2 >= SZ(nodes[k]) || finish[nodes[k][idx2]] != finish[x])
				idx2--;
			if (idx4 >= SZ(nodes[1 - k]) || finish[nodes[1 - k][idx4]] != finish[x])
				idx4--;
			idx1++;
			idx2++;
			idx3++;
			idx4++;
			if (idx1 <= idx2)
				update(1, 1, n, idx1, idx2, v, k);
			if (idx3 <= idx4)
				update(1, 1, n, idx3, idx4, -v, 1 - k);
		}
		else
		{
			cin >> x;
			int k = dis[x];
			int idx = lower_bound(ALL(starts[k]), start[x]) - starts[k].begin();
			idx++;
			cout << getVal(1, 1, n, idx, k) << endl;
		}
	}
	return 0;
}