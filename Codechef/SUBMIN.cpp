#include <iostream>
using namespace std;

#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define INF (1000 * 1000 * 1000)
#define MAXN 60

int q, k, ans, n, a[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 0, n - 1)
		cin >> a[i];
	cin >> q;
	while (q--)
	{
		cin >> k;
		ans = 0;
		FOR (i, 0, n - 1)
		{
			int mn = INF;
			FOR (j, i, n - 1)
			{
				mn = min(mn, a[j]);
				if (mn == k)
					ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}