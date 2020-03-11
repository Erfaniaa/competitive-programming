/*
	SubmissionId	:	37964378
	ContestId	:	977
	Index	:	E
	ProblemName	:	Cyclic Components
	ProblemTags	:	['dfs and similar', 'dsu', 'graphs']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int n, m, ans;
bool mark[MAXN];
vector<int> adj[MAXN], temp;

void dfs(int v) {
	mark[v] = true;
	temp.push_back(v);
	for (int i = 0; i < adj[v].size(); i++) {
		int u = adj[v][i];
		if (!mark[u])
			dfs(u);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!mark[i]) {
			temp.clear();
			dfs(i);
			bool valid = true;
			for (int j = 0; j < temp.size(); j++)
				if (adj[temp[j]].size() != 2) {
					valid = false;
					break;
				}
			if (valid)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}