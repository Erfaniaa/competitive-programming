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
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 100002
#define MOD (ll)1000000

int cnt[MAXN * 10], n, t, a, b, c, d, turn;
ll s, tmp = MOD * MOD * 100000, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> a >> b >> c >> d;
		memset(cnt, 0, sizeof cnt);
		s = d;
		ans = 0;
		turn = 0;
		cnt[s]++;
		FOR (i, 1, n - 1)
		{
			s = (a * s * s + b * s + c + tmp) % MOD;
			cnt[s]++;
		}
		FORD (i, 1000000, 0)
		{
			if (turn % 2 == 0)
				ans += (cnt[i] % 2) * i;
			else
				ans -= (cnt[i] % 2) * i;
			turn = (turn + cnt[i]) % 2;
		}
		cout << abs(ans) << "\n";
	}
	return 0;
}