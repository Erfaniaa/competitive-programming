#include <bits/stdc++.h>

using namespace std;

#define MAXN 310

int n, m, cap[MAXN][MAXN], flow[MAXN][MAXN], totalFlow, parent[MAXN];
bool mark[MAXN];

int dfs(int s, int t, int mn) {
	mark[s] = true;
	if (s == t) {
		return mn;
	}
	for (int i = 1; i <= n; i++) {
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

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		cap[x][y] = w;
	}
	while (1) {
		for (int i = 1; i <= n; i++) {
			mark[i] = false;
			parent[i] = -1;
		}
		int tmp = dfs(1, n, 1e9);
		if (tmp == 0)
			break;
		totalFlow += tmp;
		int x = n;
		while (parent[x] != -1) {
			int y = parent[x];
			flow[y][x] += tmp;
			flow[x][y] -= tmp;
			x = y;
		}
	}
	cout << totalFlow << endl;
	return 0;
}