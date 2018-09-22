/*
	SubmissionId	:	22446426
	ContestId	:	740
	Index	:	D
	ProblemName	:	Alyona and a tree
	ProblemTags	:	['binary search', 'data structures', 'dfs and similar', 'graph matchings', 'graphs']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int n, a[MAXN];
vector<int> nodes;
vector<pair<int, int> > adj[MAXN];
vector<long long> sum;
int mark[MAXN], ans[MAXN], up[MAXN], down[MAXN];

void dfs(int v, int e)
{
	mark[v] = 1;
	nodes.push_back(v);
	if (sum.size() == 0)
		sum.push_back(e);
	else
		sum.push_back(sum[sum.size() - 1] + e);
	vector<long long>::iterator lb = lower_bound(sum.begin(), sum.end(), sum[sum.size() - 1] - a[v]);
	int idx = lb - sum.begin();
	up[nodes[idx]]++;
	down[nodes[nodes.size() - 1]]++;
	for (int i = 0; i < adj[v].size(); i++)
	{
		pair<int, int> u = adj[v][i];
		if (!mark[u.first])
			dfs(u.first, u.second);
	}
	nodes.pop_back();
	sum.pop_back();
}

int dfs2(int v)
{
	int ret = down[v];
	mark[v] = 1;
	for (int i = 0; i < adj[v].size(); i++)
	{
		pair<int, int> u = adj[v][i];
		if (!mark[u.first])
			ret += dfs2(u.first) - up[u.first];
	}
	return ans[v] = ret;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 2; i <= n; i++)
	{
		int x, w;
		cin >> x >> w;
		adj[i].push_back(make_pair(x, w));
		adj[x].push_back(make_pair(i, w));
	}
	dfs(1, 0);
	memset(mark, 0, sizeof mark);
	dfs2(1);
	for (int i = 1; i <= n; i++)
		cout << ans[i] - 1 << " ";
	cout << endl;
	return 0;
}