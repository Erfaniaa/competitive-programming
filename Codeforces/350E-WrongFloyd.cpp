/*
	SubmissionId	:	4633387
	ContestId	:	350
	Index	:	E
	ProblemName	:	Wrong Floyd
	ProblemTags	:	['brute force', 'constructive algorithms', 'dfs and similar', 'graphs']
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
#define mp make_pair
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 400

bool mark[MAXN];
int n, m, k, u, v;
vector<pii> edges;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	FOR (i, 1, k)
	{
		int a;
		cin >> a;
		mark[a] = true;
	}
	if (k == n || m < 2 || m == n * (n - 1) / 2)
	{
		cout << -1 << endl;
		return 0;
	}
	FOR (i, 1, n)
		if (!mark[i])
		{
			u = i;
			break;
		}
	bool selected = false;
	FOR (i, 1, n)
		if (mark[i])
		{
			v = i;
			selected = true;
			break;
		}
	if (!selected)
	{
		cout << -1 << endl;
		return 0;
	}
	FOR (j, 1, n)
		if (SZ(edges) < m)
			if (j != u)
				edges.pb(mp(u, j));
	FOR (i, 1, n)
		FOR (j, i + 1, n)
		{
			pii e = mp(i, j);
			if (SZ(edges) < m)
				if (i != u && i != v)
					if (j != u && j != v)
						edges.pb(e);
		}
	FOR (j, 1, n)
		if (SZ(edges) < m)
			if (j != v && j != u && !mark[j])
				edges.pb(mp(v, j));
	if (SZ(edges) == m)
	{
		FOR (i, 0, m - 1)
			cout << edges[i].X << " " << edges[i].Y << endl;
	}
	else
		cout << -1 << endl;
	return 0;
}