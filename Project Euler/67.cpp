//Besmellah
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
#define MAXN 120

ll ans, d[MAXN][MAXN];
int a[MAXN][MAXN], n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
		FOR (j, 1, i)
			cin >> a[i][j];
	FOR (i, 1, n)
		FOR (j, 1, i)
		{
			d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + a[i][j];
			ans = max(ans, d[i][j]);
		}
	debug(ans);
	return 0;
}