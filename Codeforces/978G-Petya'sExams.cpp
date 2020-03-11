/*
	SubmissionId	:	38181835
	ContestId	:	978
	Index	:	G
	ProblemName	:	Petya's Exams
	ProblemTags	:	['greedy', 'implementation', 'sortings']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 210;

int qDay[MAXN], examDay[MAXN], prepDays[MAXN], n, m;
int flow[MAXN][MAXN], cap[MAXN][MAXN], expectedTotalFlow, totalFlow, parent[MAXN], ans[MAXN];
bool mark[MAXN];

int dfs(int s, int t, int mn) {
	mark[s] = true;
	if (s == t) {
		return mn;
	}
	for (int i = 0; i <= n + m + 1; i++) {
		if (cap[s][i] - flow[s][i] > 0 && !mark[i]) {
			int f = dfs(i, t, min(mn, cap[s][i] - flow[s][i]));
			if (f == 0)
				continue;
			parent[i] = s;
			return f;
		}
	}
	// mark[t] = false;
	return 0;
	// return 1e9;
}

void addEdge(int x, int y, int w) {
	cap[x][y] = w;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> qDay[i] >> examDay[i] >> prepDays[i];
		for (int j = qDay[i]; j < examDay[i]; j++)
			addEdge(j, n + i, 1);
		ans[examDay[i]] = m + 1;
	}
	for (int i = 1; i <= n; i++)
		if (ans[i] == 0)
			addEdge(0, i, 1);
	for (int i = n + 1; i <= n + m; i++) {
		addEdge(i, n + m + 1, prepDays[i - n]);
		expectedTotalFlow += prepDays[i - n];
	}
	while (1) {
		for (int i = 0; i <= n + m + 1; i++) {
			mark[i] = false;
			parent[i] = -1;
		}
		int tmp = dfs(0, n + m + 1, 1e9);
		if (tmp == 0)
			break;
		totalFlow += tmp;
		int x = n + m + 1;
		while (parent[x] != -1) {
			int y = parent[x];
			flow[y][x] += tmp;
			flow[x][y] -= tmp;
			x = y;
		}
	}
	if (totalFlow == expectedTotalFlow) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (flow[i][j + n] > 0) {
					ans[i] = j;
					break;
				}
		for (int i = 1; i <= n; i++)
			cout << ans[i] << " ";
	} else
		cout << -1 << endl;
	return 0;
}