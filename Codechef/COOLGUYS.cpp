//
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

ll gcd(ll a, ll b)
{
	if (!b)
		return a;
	else
		return gcd(b, a % b);
}

int n, t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	FOR (tt, 1, t)
	{
		cin >> n;
		ll sum = 0;
		FOR (i, 1, (n + 1) / 2)
			sum += n / i;
		sum += n / 2;
		ll total = (ll)n * n;
		ll g = gcd(sum, total);
		//sum /= g;
		//total /= g;
		cout << sum << "/" << total << endl;
	}
	return 0;
}
