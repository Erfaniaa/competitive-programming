/*
	SubmissionId	:	42380651
	ContestId	:	1037
	Index	:	D
	ProblemName	:	Valid BFS?
	ProblemTags	:	['dfs and similar', 'graphs', 'shortest paths', 'trees']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int p[MAXN], n, dis[MAXN];
vector<int> a, adj[MAXN], q;

bool cmp(int x, int y) {
	if (p[x] != p[y])
		return p[x] < p[y];
	else
		return x < y;
}

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		p[x] = i;
		a.push_back(x);
	}
	for (int i = 0; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end(), cmp);
	}
	memset(dis, -1, sizeof dis);
	q.push_back(1);
	dis[1] = 0;
	for (int i = 0; i < q.size(); i++) {
		int v = q[i];
		if (q[i] != a[i]) {
			cout << "No" << endl;
			return 0;
		}
		for (int j = 0; j < adj[v].size(); j++) {
			int u = adj[v][j];
			if (dis[u] == -1) {
				dis[u] = dis[v] + 1;
				q.push_back(u);
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}