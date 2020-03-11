#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

int n, x, a[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> x;
	FOR (i, 0, n - 1)
		cin >> a[i];
	sort(a, a + n);
	int l = 0;
	int r = n - 1;
	int idx = -1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (a[m] >= x)
		{
			r = m - 1;
			idx = m;
		}
		else
			l = m + 1;
	}
	debug(idx);
	debug(a[idx]);
	return 0;
}