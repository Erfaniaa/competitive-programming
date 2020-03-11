/*
	SubmissionId	:	4770603
	ContestId	:	354
	Index	:	A
	ProblemName	:	Vasya and Robot
	ProblemTags	:	['brute force', 'greedy', 'math']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<fstream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

ll n, l, r, qL, qR, sum[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l >> r >> qL >> qR;
	FOR (i, 1, n)
	{
		ll a;
		cin >> a;
		sum[i] = sum[i - 1] + a;
	}
	ll ans = (ll)1000 * 1000 * 1000 * 1000;
	FOR (i, 0, n)
	{
		ll x = sum[i] * l + (sum[n] - sum[i]) * r;
		ll j = n - i;
		if (i - j >= 2)
			x += (i - j - 1) * qL;
		if (j - i >= 2)
			x += (j - i - 1) * qR;
		ans = min(ans, x);
	}
	cout << ans << endl;
	return 0;
}