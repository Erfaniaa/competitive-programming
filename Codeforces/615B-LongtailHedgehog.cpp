/*
	SubmissionId	:	15242264
	ContestId	:	615
	Index	:	B
	ProblemName	:	Longtail Hedgehog
	ProblemTags	:	['dp', 'graphs']
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

int maxPath[MAXN];
long long ans;
vector<int> adj[MAXN];

int dfs(int x)
{
	if (maxPath[x])
		return maxPath[x];
	maxPath[x] = 1;
	for (int i = 0; i < (int)adj[x].size(); i++)
	{
		int u = adj[x][i];
		if (u < x)
			maxPath[x] = max(maxPath[x], 1 + dfs(u));
	}
	return maxPath[x];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		ans = max(ans, (long long)adj[i].size() * dfs(i));
	cout << ans << endl;
	return 0;
}