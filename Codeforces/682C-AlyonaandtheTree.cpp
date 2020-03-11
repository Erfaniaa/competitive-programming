/*
	SubmissionId	:	18556830
	ContestId	:	682
	Index	:	C
	ProblemName	:	Alyona and the Tree
	ProblemTags	:	['dfs and similar', 'dp', 'graphs', 'trees']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100010], wei[100010];
int n, a[100010], ans;
bool mark[100010];

void dfs(int v, long long sum, long long mx, bool rem)
{
	mark[v] = true;
	if (mx < sum - a[v] || rem)
	{
		ans++;
		rem = true;
	}
	for (int i = 0; i < adj[v].size(); i++)
	{
		int u = adj[v][i];
		int w = wei[v][i];
		if (!mark[u])
			dfs(u, sum + w, min(sum + w, mx), rem);
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 2; i <= n; i++)
	{
		int p, w;
		cin >> p >> w;
		adj[p].push_back(i);
		adj[i].push_back(p);
		wei[p].push_back(w);
		wei[i].push_back(w);
	}
	dfs(1, 0, 0, false);
	cout << ans << endl;
	return 0;
}