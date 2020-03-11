/*
	SubmissionId	:	5577000
	ContestId	:	379
	Index	:	C
	ProblemName	:	New Year Ratings Change
	ProblemTags	:	['greedy', 'sortings']
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
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 300010

ll n;
pair<ll, ll> a[MAXN];
ll ans[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
	{
		cin >> a[i].X;
		a[i].Y = i;
	}
	sort(a + 1, a + n + 1);
	ll mx = -INF;
	FOR (i, 1, n)
	{
		mx = max(a[i].X - 1, mx) + 1;
		ans[a[i].Y] = mx;
	}
	FOR (i, 1, n)
		cout << ans[i] << " ";
	return 0;
};