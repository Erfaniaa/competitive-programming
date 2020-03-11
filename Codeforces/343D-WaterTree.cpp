/*
	SubmissionId	:	5169330
	ContestId	:	343
	Index	:	D
	ProblemName	:	Water Tree
	ProblemTags	:	['data structures', 'dfs and similar', 'trees']
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
#define MAXN 500010

int n, q, cnt, start[MAXN], finish[MAXN];
int seg1[6 * MAXN], seg2[6 * MAXN], mark[6 * MAXN];
vector<int> adj[MAXN];

void dfs(int v, int f)
{
	start[v] = ++cnt;
	FOR (i, 0, SZ(adj[v]) - 1)
	{
		int u = adj[v][i];
		if (u != f)
			dfs(u, v);
	}
	finish[v] = cnt;
}

void makeGood(int v)
{
	if (mark[v])
	{
		mark[v] = false;
		mark[2 * v] = mark[2 * v + 1] = true;
		seg1[2 * v] = seg1[2 * v + 1] = seg1[v];
	}
}

void fill(int v, int vl, int vr, int l, int r, int val)
{
	makeGood(v);
	if (l <= vl && vr <= r)
	{
		seg1[v] = val;
		if (vl == 3 && vr == 3)
			debug(val);
		mark[v] = true;
		return;
	}
	if (r < vl || l > vr)
		return;
	seg1[v] = val;
	if (vl == vr)
		return;
	int m = (vl + vr) / 2;
	fill(2 * v, vl, m, l, r, val);
	fill(2 * v + 1, m + 1, vr, l, r, val);
}

int lastFill(int v, int vl, int vr, int p)
{
	makeGood(v);
	int m = (vl + vr) / 2;
	if (vl == vr)
		return seg1[v];
	if (p <= m)
		return lastFill(2 * v, vl, m, p);
	else
		return lastFill(2 * v + 1, m + 1, vr, p);
}

void empty(int v, int vl, int vr, int p, int val)
{
	int m = (vl + vr) / 2;
	if (vl == 3 && vr == 3)
		debug(val);
	seg2[v] = val;
	if (vl == vr)
		return;
	if (p <= m)
		empty(2 * v, vl, m, p, val);
	else
		empty(2 * v + 1, m + 1, vr, p, val);
}

int lastEmpty(int v, int vl, int vr, int l, int r)
{
	if (l <= vl && vr <= r)
		return seg2[v];
	if (r < vl || vr < l)
		return 0;
	int m = (vl + vr) / 2;
	return max(lastEmpty(2 * v, vl, m, l, r), lastEmpty(2 * v + 1, m + 1, vr, l, r));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n - 1)
	{
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, -1);
	FOR (i, 1, n)
		cerr << start[i] << " " << finish[i] << endl;
	cin >> q;
	FOR (i, 1, q)
	{
		int a, v;
		cin >> a >> v;
		if (a == 1)
			fill(1, 1, n, start[v], finish[v], i);
		if (a == 2)
			empty(1, 1, n, start[v], i);
		if (a == 3)
		{
			//debug(lastFill(1, 1, n, start[v]));
			//debug(lastEmpty(1, 1, n, start[v], finish[v]));
			FOR (j, 1, 9)
				;//cerr << seg1[i] << " - " << seg2[i] << endl;
			cout << (int)(lastFill(1, 1, n, start[v]) > lastEmpty(1, 1, n, start[v], finish[v])) << endl;
		}
	}
	return 0;
}