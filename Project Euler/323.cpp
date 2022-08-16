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
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF (1000 * 1000 * 1000)
#define MAXN 40

int n, m;
long double ans, p[100010][MAXN];
long long c[MAXN][MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	p[0][0] = 1;
	for (int i = 0; i <= n; i++)
		c[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	for (int i = 1; i <= m; i++)
	{
		for (int a = 0; a <= n; a++)
			for (int b = 0; b <= a; b++)
				if (b != n)
					p[i][a] += p[i - 1][b] * c[n - b][a - b] / (1ll << (n - b));
		ans += p[i][n] * i;
	}
	cout.precision(10);
	cout << fixed << ans << endl;
	return 0;
}