/*
	SubmissionId	:	19348042
	ContestId	:	701
	Index	:	E
	ProblemName	:	Connecting Universities
	ProblemTags	:	['dfs and similar', 'graphs']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int color[MAXN], n, k, dis[MAXN];
long long sum[MAXN], cnt[MAXN], ans = (long long)MAXN * (long long)MAXN;
vector<int> adj[MAXN];

void dfs(int v, int f, int d)
{
	for (int u: adj[v])
		if (u != f)
			dfs(u, v, d + 1);
	cnt[v] = color[v];
	for (int u: adj[v])
		if (u != f)
			cnt[v] += cnt[u];
	for (int u: adj[v])
		if (u != f)
			sum[v] += sum[u] + cnt[u];
	dis[v] = d;
}

void dfs2(int v, int f, long long x, long long y)
{
	if (f != -1)
	{
		// if (cnt[v] == k)
			ans = min(ans, y);
	}
	// cout << cnt[v] << endl;
	// cout << v << " " << x << endl;
	for (int u: adj[v])
		if (u != f)
			dfs2(u, v, x - cnt[u] + (2 * k - cnt[u]), x);
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < 2 * k; i++)
	{
		int x;
		cin >> x;
		color[x] = 1;
	}
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, -1, 0);
	long long tmp = 0;
	for (int i = 1; i <= n; i++)
		tmp += dis[i] * color[i];
	// cout << tmp << endl;
	dfs2(1, -1, tmp, 0);
	cout << ans << endl;
	return 0;
}