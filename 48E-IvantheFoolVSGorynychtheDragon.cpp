/*
	SubmissionId	:	4127541
	ContestId	:	48
	Index	:	E
	ProblemName	:	Ivan the Fool VS Gorynych the Dragon
	ProblemTags	:	['dp', 'games', 'graphs']
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
#include<list>
#include<queue>
#include<fstream>
#include<sstream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define MAXN 1001
#define INF 1000000000

vector<pii> q;
bool isDag = true;
int mark[201 * 201];
vector<int> adj[201 * 201];
int H, T, R, h1[201], h2[201], t1[201], t2[201], n1, n2;
int d[201 * 201];

int hash(int h, int t)
{
	return 201 * h + t;
}

int dagMaxPath(int v)
{
	if (d[v] != -1)
		return d[v];
	if (SZ(adj[v]) == 0)
	{
		d[v] = 1;
		return 1;
	}
	int ans = 0;
	for (int i = 0; i < SZ(adj[v]); i++)
		ans = max(ans, dagMaxPath(adj[v][i]) + 1);
	return d[v] = ans;
}

void dfs(int v)
{
	mark[v] = 1;
	for (int i = 0; i < SZ(adj[v]); i++)
		if (!mark[adj[v][i]])
			dfs(adj[v][i]);
		else if (mark[adj[v][i]] == 1)
		{
			isDag = false;
			return;
		}
	mark[v] = 2;
}

int shortestPath(int v)
{
	q.pb(mp(v, 0));
	mark[v] = true;
	for (int i = 0; i < SZ(q); i++)
		for (int j = 0; j < SZ(adj[q[i].X]); j++)
		{
			int u = adj[q[i].X][j];
			if (!mark[u])
			{
				mark[u] = true;
				q.pb(mp(u, q[i].Y + 1));
				if (u == 0)
					return q[i].Y + 1;
			}
		}
	return INF;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> H >> T >> R;
	cin >> n1;
	for (int i = 1; i <= n1; i++)
		cin >> h1[i] >> t1[i];
	cin >> n2;
	for (int i = 1; i <= n2; i++)
		cin >> h2[i] >> t2[i];
	for (int h = 0; h <= R; h++)
		for (int t = 0; h + t <= R; t++)
		{
			int hp, tp;
			for (int i = 1; i <= min(n1, h); i++)
			{
				hp = h - i + h1[i];
				tp = t + t1[i];
				if (hp >= 0 && tp >= 0 && hp + tp <= R)
					adj[hash(h, t)].pb(hash(hp, tp));
			}
			for (int i = 1; i <= min(n2, t); i++)
			{
				hp = h + h2[i];
				tp = t - i + t2[i];
				if (hp >= 0 && tp >= 0 && hp + tp <= R)
					adj[hash(h, t)].pb(hash(hp, tp));
			}
		}
	memset(mark, 0, sizeof mark);
	int ans = shortestPath(hash(H, T));
	if (ans != INF)
	{
		cout << "Ivan" << endl;
		cout << ans << endl;
		return 0;
	}
	memset(mark, 0, sizeof mark);
	dfs(hash(H, T));
	if (!isDag)
	{
		cout << "Draw" << endl;
		return 0;
	}
	memset(d, -1, sizeof d);
	ans = dagMaxPath(hash(H, T));
	cout << "Zmey" << endl;
	cout << ans << endl;
	return 0;
}
