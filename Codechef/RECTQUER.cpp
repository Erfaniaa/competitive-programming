#include<iostream>
using namespace std;

#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define MAXN 301

int sum[11][MAXN][MAXN], n, m, a[MAXN][MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (y, 1, n)
		FOR (x, 1, n)
			cin >> a[x][y];
	FOR (k, 1, 10)
		FOR (y, 1, n)
			FOR (x, 1, n)
				sum[k][x][y] = (a[x][y] == k) + sum[k][x - 1][y] + sum[k][x][y - 1] - sum[k][x - 1][y - 1];
	cin >> m;
	FOR (i, 1, m)
	{
		int ans = 0, x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		FOR (k, 1, 10)
			ans += (sum[k][x2][y2] - sum[k][x1 - 1][y2] - sum[k][x2][y1 - 1] + sum[k][x1 - 1][y1 - 1]) > 0;
		cout << ans << "\n";
	}
	return 0;
}