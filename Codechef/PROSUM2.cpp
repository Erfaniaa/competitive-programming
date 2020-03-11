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
#define MAXN 100010

int t, a[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		ll n = 30, cnt = 0, tmp = 0, ans = 0, cnt2 = 0;
		FOR (i, 1, n)
			a[i] = rand() % n;
		//sort(a + 1, a + n + 1);
		FOR (i, 1, n)
			FOR (j, i + 1, n)
				if (a[i] * a[j] > a[i] + a[j])
				{
					//if (a[i] <= 2 || a[j] <= 2)
					//	cout << "(" << a[i] << ", " << a[j] << ")" << endl;
					tmp++;
				}
		FOR (i, 1, n)
		{
			cout << a[i] << " ";
			if (a[i] == 2)
				cnt2++;
			if (a[i] > 2)
				cnt++;
		}
		cout << endl;
		cout << (cnt * (cnt - 1) / 2) + cnt * cnt2 << "\n";
		debug(tmp);
	}
	return 0;
}