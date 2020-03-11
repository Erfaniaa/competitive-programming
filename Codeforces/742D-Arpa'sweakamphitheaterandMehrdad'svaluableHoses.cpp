/*
	SubmissionId	:	22754357
	ContestId	:	742
	Index	:	D
	ProblemName	:	Arpa's weak amphitheater and Mehrdad's valuable Hoses
	ProblemTags	:	['dfs and similar', 'dp', 'dsu']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010
#define MAXW 1010

int comp[MAXN], compSize[MAXN], compSum[MAXN], compBSum[MAXN], n, m, wei;
int w[MAXN], b[MAXN], comps;
int dp[MAXN][MAXW], ans;
vector<int> adj[MAXN], nodes;

void dfs(int v, int c)
{
	nodes.push_back(v);
	comp[v] = c;
	compSize[c]++;
	compSum[c] += w[v];
	compBSum[c] += b[v];
	for (int i = 0; i < adj[v].size(); i++)
		if (!comp[adj[v][i]])
			dfs(adj[v][i], c);
}

int main()
{
	cin >> n >> m >> wei;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		if (!comp[i])
			dfs(i, ++comps);
	int lastCmp = -1, curCmpNodes = 0;
	for (int i = 0; i < nodes.size(); i++)
	{
		int v = nodes[i];
		int cmp = comp[v];
		curCmpNodes++;
		if (lastCmp != cmp)
			curCmpNodes = 1;
		for (int j = 1; j <= wei; j++)
		{
			dp[i + 1][j] = dp[i][j];
			if (j - w[v] >= 0)
				dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1 - curCmpNodes][j - w[v]] + b[v]);
			if (j - compSum[cmp] >= 0 && curCmpNodes == compSize[cmp])
				dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1 - compSize[cmp]][j - compSum[cmp]] + compBSum[cmp]);
		}
		lastCmp = cmp;
	}
	for (int i = 0; i <= wei; i++)
		ans = max(ans, dp[n][i]);
	cout << ans << endl;
	return 0;
}