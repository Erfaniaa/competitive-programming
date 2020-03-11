#include <bits/stdc++.h>

using namespace std;

const int MAXN = 43;
const int MAXDPSIZE = (1 << (MAXN / 2)) + 10;

int t, n, m, a[MAXN], firstPartNeighbors[MAXN];
long long dp[MAXDPSIZE], ans;
bool isClique[MAXDPSIZE], mat[MAXN][MAXN];
unordered_map<int, int> factorsMap;
set<pair<int, int> > factorsSet;

void factorize(int x) {
	for (int i = 2; i * i <= x; i++)
		while (x % i == 0) {
			factorsSet.erase({i, factorsMap[i]});
			factorsMap[i]++;
			factorsSet.insert({i, factorsMap[i]});
			if (factorsMap[i] >= 3) //for optimization
				return;
			x /= i;
		}
	if (x > 1) {
		factorsSet.erase({x, factorsMap[x]});
		factorsMap[x]++;
		factorsSet.insert({x, factorsMap[x]});
	}
}

bool adjacent(int x, int y) {
	factorsMap.clear();
	factorsSet.clear();
	factorize(x);
	factorize(y);
	for (auto i: factorsSet)
		if (i.second >= 3)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		memset(mat, 0, sizeof mat);
		memset(firstPartNeighbors, 0, sizeof firstPartNeighbors);
		int half = n / 2;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (adjacent(a[i], a[j])) {
					if (j < half)
						firstPartNeighbors[i] |= (1 << j);
					if (i < half)
						firstPartNeighbors[j] |= (1 << i);
					mat[i][j] = mat[j][i] = true;
				}
		isClique[0] = true;
		for (int mask = 1; mask < (1 << half); mask++) {
			int v = __builtin_ctz(mask);
			int mask2 = (mask ^ (1 << v));
			if (!isClique[mask2]) {
				isClique[mask] = false;
				continue;
			}
			isClique[mask] = true;
			for (int i = 0; i < half; i++) {
				if ((mask2 & (1 << i)) && !mat[v][i]) {
					isClique[mask] = false;
					break;
				}
			}
		}
		dp[0] = 1;
		for (int mask = 1; mask < (1 << (n - half)); mask++) {
			int v = __builtin_ctz(mask);
			int mask2 = (mask ^ (1 << v));
			dp[mask] = dp[mask2];
			int mask3 = 0;
			for (int i = 0; i < n - half; i++)
				if (mat[v + half][i + half] && ((1 << i) & mask))
					mask3 |= (1 << i);
			dp[mask] += dp[mask3];
		}
		ans = 0;
		for (int mask = 0; mask < (1 << half); mask++) {
			if (!isClique[mask])
				continue;
			int mask2 = 0;
			for (int i = half; i < n; i++) {
				if ((firstPartNeighbors[i] & mask) == mask)
					mask2 |= (1 << (i - half));
			}
			ans += dp[mask2];
		}
		cout << ans << endl;
	}
	return 0;
}