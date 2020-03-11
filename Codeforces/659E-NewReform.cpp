/*
	SubmissionId	:	17056741
	ContestId	:	659
	Index	:	E
	ProblemName	:	New Reform
	ProblemTags	:	['data structures', 'dfs and similar', 'dsu', 'graphs', 'greedy']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

int mark[MAXN], n, m, ans;
bool hasCycle[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int c, int par)
{
	mark[v] = c;
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		if (!mark[u])
			dfs(u, c, v);
		else if (u != par)
			hasCycle[c] = true;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int comps = 0;
	for (int i = 1; i <= n; i++)
		if (!mark[i])
			dfs(i, ++comps, -1);
	for (int i = 1; i <= comps; i++)
		if (!hasCycle[i])
			ans++;
	cout << ans << endl;
	return 0;
}