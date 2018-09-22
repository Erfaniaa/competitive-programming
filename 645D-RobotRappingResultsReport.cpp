/*
	SubmissionId	:	16794229
	ContestId	:	645
	Index	:	D
	ProblemName	:	Robot Rapping Results Report
	ProblemTags	:	['binary search', 'dp', 'graphs']
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

int n, m, x[MAXN], y[MAXN], inDeg[MAXN];
vector<int> adj[MAXN], q;

void addEdge(int idx)
{
	adj[x[idx]].push_back(y[idx]);
	inDeg[y[idx]]++;
}

bool check(int t)
{
	for (int i = 1; i <= n; i++)
	{
		adj[i].clear();
		inDeg[i] = 0;
	}
	for (int i = 1; i <= t; i++)
		addEdge(i);
	q.clear();
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (inDeg[i] == 0)
		{
			cnt++;
			q.push_back(i);
		}
	if (cnt > 1)
		return false;
	for (int i = 0; i < (int)q.size(); i++)
	{
		int v = q[i];
		cnt = 0;
		for (int j = 0; j < (int)adj[v].size(); j++)
		{
			int u = adj[v][j];
			inDeg[u]--;
			if (inDeg[u] == 0)
			{
				cnt++;
				q.push_back(u);
			}
		}
		if (cnt > 1)
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> x[i] >> y[i];
	int l = 0, r = m, ans = m;
	while (r >= l)
	{
		int mid = (l + r) / 2;
		if (check(mid))
		{
			r = mid - 1;
			ans = min(ans, mid);
		}
		else
			l = mid + 1;
	}
	if (ans == m && !check(m))
		ans = -1;
	cout << ans << endl;
	return 0;
}