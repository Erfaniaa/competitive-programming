#include <bits/stdc++.h>
 
#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
 
#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()
 
using namespace std;
 
inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}
 
struct Song {
	int a, p, v;
 
	bool operator <(const Song& ot) const {
		return a < ot.a;
	}
};
 
void solve() {
	int n = nxt(), m = nxt(), p = nxt();
	vector<Song> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].a = nxt() - 1;
		a[i].p = nxt();
		a[i].v = nxt();
	}
	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		b[i] = nxt();
	}
	vector<int> total(m);
	for (int i = 0; i < n; ++i) {
		total[a[i].a] += a[i].v;
	}
	sort(all(a));
 
	vector<vector<int>> dp(n + 1, vector<int>(p + 1, -1));
	int cur_album = 0, initial = 0;
	dp[0][p] = 0;
	for (int i = 0; i < n; ++i) {
		dp[i + 1] = dp[i];
		for (int j = a[i].p; j <= p; ++j) {
			if (dp[i][j] > -1) {
				dp[i + 1][j - a[i].p] = max(dp[i + 1][j - a[i].p], dp[i][j] + a[i].v);
			}
		}
		if (i == n - 1 || cur_album < a[i + 1].a) {
			for (int j = b[cur_album]; j <= p; ++j) {
				if (dp[initial][j] > -1) {
					dp[i + 1][j - b[cur_album]] = max(dp[i + 1][j - b[cur_album]], dp[initial][j] + total[cur_album]);
				}
			}
			if (i < n - 1) {
				cur_album = a[i + 1].a;
				initial = i + 1;
			}
		}
	}
 
	cout << *max_element(all(dp.back())) << "\n";
}
 
int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
	int t = 1; // nxt();
	while (t--) {
		solve();
	}
 
	return 0;
} 