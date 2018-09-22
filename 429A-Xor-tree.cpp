/*
	SubmissionId	:	6588451
	ContestId	:	429
	Index	:	A
	ProblemName	:	Xor-tree
	ProblemTags	:	['dfs and similar', 'trees']
	ProgrammingLanguage	:	GNU C++
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

int n, init[MAXN], goal[MAXN];
vector<int> adj[MAXN], ans;

void dfs(int v, int f, int depth, int even, int odd)
{
	if (depth % 2 == 0)
	{
		if ((init[v] + even) % 2 != goal[v])
		{
			ans.pb(v);
			even = 1 - even;
		}
	}
	else
	if ((init[v] + odd) % 2 != goal[v])
		{
			ans.pb(v);
			odd = 1 - odd;
		}	
	for (int i = 0; i < SZ(adj[v]); i++)
		if (adj[v][i] != f)
			dfs(adj[v][i], v, depth + 1, even, odd);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for (int i = 1; i <= n; i++)
		cin >> init[i];
	for (int i = 1; i <= n; i++)
		cin >> goal[i];
	dfs(1, -1, 0, 0, 0);
	cout << SZ(ans) << "\n";
	for (int i = 0; i < SZ(ans); i++)
		cout << ans[i] << "\n";
	return 0;
}