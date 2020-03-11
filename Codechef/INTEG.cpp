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
#define MAXN 100010

ll n, x;
vector<ll> v;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	FOR (i, 0, n - 1)
	{
		int a;
		cin >> a;
		if (a < 0)
			v.pb(-a);
	}
	cin >> x;
	sort(ALL(v));
	n = SZ(v);
	ll sum = 0;
	if (x > n)
	{
		FOR (i, 0, n - 1)
			sum += v[i];
		cout << sum << endl;
		return 0;
	}
	ll k = min(n - x, n - 1);
	if (k >= 0/* && n - x <= n - 1*/)
	{
		ll mx = -1;
		FOR (i, 0, k)
			mx = max(mx, v[i]);
		sum += mx * x;
		FOR (i, 0, n - 1)
			sum += max(v[i] - mx, (ll)0);
		cout << sum << endl;
	}
	return 0;
}
