#include <iostream>
using namespace std;

#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define INF (1000 * 1000 * 1000)
#define MAXN 500005

inline int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

inline int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int a[MAXN], l[MAXN * 2], r[MAXN * 2], n, k, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	FOR (i, 1, n)
		cin >> a[i];
	FOR (i, 1, n)
	{
		if (!r[a[n + 1 - i]])
			r[a[n + 1 - i]] = i;
		if (!l[a[i]])
			l[a[i]] = i;
	}
	ans = INF;
	FOR (i, 1, n)
	{
		if (a[i] < k && r[k - a[i]] != 0 && 2 * a[i] != k)
			ans = min(ans, max(i, r[k - a[i]]));
		if (a[i] < k && l[k - a[i]] != 0 && 2 * a[i] != k)
			ans = min(ans, max(i, l[k - a[i]]));
		if (a[n + 1 - i] < k && l[k - a[n + 1 - i]] != 0 && 2 * a[n + 1 - i] != k)
			ans = min(ans, max(i, r[k - a[n + 1 - i]]));
	}
	if (ans == INF)
		ans = -1;
	cout << ans << "\n";
	return 0;
}