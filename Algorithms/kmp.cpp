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

string s, t;
int k, f[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> t;
	FOR (i, 0, SZ(s) - 1)
		cout << i % 10;
	cout << endl;
	FOR (i, 1, SZ(t) - 1)
	{
		while (k > 0 && t[k] != t[i])
			k = f[k];
		if (t[k] == t[i])
			k++;
		f[i + 1] = k;
	}
	k = 0;
	FOR (i, 0, SZ(s) - 1)
	{
		while (k > 0 && s[i] != t[k])
			k = f[k];
		if (s[i] == t[k])
			k++;
		if (k == SZ(t))
		{
			debug(i);
			k = f[k];
		}
	}
	return 0;
}