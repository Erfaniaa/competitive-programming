/*
	SubmissionId	:	5673921
	ContestId	:	380
	Index	:	A
	ProblemName	:	Sereja and Prefixes
	ProblemTags	:	['binary search', 'brute force']
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
#define MAXN 100010

vector<ll> s;
ll l[MAXN], c[MAXN];
int a[MAXN], m, n;

inline int solve(ll x)
{
	int idx = lower_bound(ALL(s), x) - s.begin();
	if (a[idx] != -1)
		return a[idx];
	else
	{
		x = (x - s[idx - 1]) % l[idx];
		if (x == 0)
			x = l[idx];
		return solve(x);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m;
	s.pb(0);
	FOR (i, 1, m)
	{
		int q;
		cin >> q;
		if (q == 2)
		{
			cin >> l[i] >> c[i];
			a[i] = -1;
			s.pb(s[SZ(s) - 1] + l[i] * c[i]);
		}
		else
		{
			cin >> a[i];
			l[i] = -1;
			c[i] = -1;
			s.pb(s[SZ(s) - 1] + 1);
		}
	}
	cin >> n;
	FOR (i, 1, n)
	{
		ll x;
		cin >> x;
		cout << solve(x) << " ";
	}
	return 0;
}