#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<fstream>
#include<sstream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define MAXN 510

int t, cnt[MAXN];
bool c[MAXN][MAXN], np[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	np[1] = true;
	FOR (i, 2, 501)
		if (!np[i])
			FOR (j, 2, 501 / i)
				np[i * j] = true;
	cnt[1] = 0;
	FOR (i, 2, 501)
		cnt[i] = (1 - np[i]) + cnt[i - 1];
	cin >> t;
	FOR (tt, 1, t)
	{
		int ans = 0, xx, yy;
		memset(c, 0, sizeof c);
		cin >> yy >> xx;
		FOR (y, 1, yy)
			FOR (x, 1, xx)
			{
				char a;
				cin >> a;
				c[x][y] = (a == '^');
			}
		FOR (y, 3, yy - 2)
			FOR (x, 3, xx - 2)
			{
				int l, m = min(x, y);
				m = min(m, xx - x + 1);
				m = min(m, yy - y + 1);
				FOR (k, 0, m)
				{
					l = k;
					if (!(c[x - k][y] && c[x + k][y] && c[x][y - k] && c[x][y + k]))
						break;
				}
				if (l - 1 >= 2)
				{
					ans += cnt[l - 1];
					//debug(l - 1);
				}
			}
		cout << ans << endl;
	}
	return 0;
}
