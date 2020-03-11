/*
	SubmissionId	:	5715093
	ContestId	:	382
	Index	:	C
	ProblemName	:	Arithmetic Progression
	ProblemTags	:	['implementation', 'sortings']
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

int n;
vector<ll> v, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
	{
		ll a;
		cin >> a;
		v.pb(a);
	}
	sort(ALL(v));
	if (SZ(v) == 1)
	{
		cout << -1 << endl;
		return 0;
	}
	if (SZ(v) == 2)
	{
		ll d = v[1] - v[0];
		if (d != 0)
		{
			ans.pb(v[0] - d);
			ans.pb(v[1] + d);
			if (d % 2 == 0)
				ans.pb(v[0] + (d / 2));
		}
		else
			ans.pb(v[0]);
	}
	else
	{
		set<ll> s;
		ll d = (ll)INF * 10;
		FOR (i, 1, SZ(v) - 1)
		{
			s.insert(v[i] - v[i - 1]);
			d = min(d, v[i] - v[i - 1]);
		}
		if (SZ(s) == 1)
		{
			ans.pb(v[0] - d);
			if (d != 0)
				ans.pb(v[SZ(v) - 1] + d);
		}
		if (SZ(s) == 2)
		{
			if (d != 0)
			{
				int cnt = 0, idx;
				FOR (i, 1, SZ(v) - 1)
					if (v[i] - v[i - 1] == 2 * d)
					{
						idx = i;
						cnt++;
					}
				if (cnt == 1)
					ans.pb((v[idx] + v[idx - 1]) / 2);
			}
		}
	}
	sort(ALL(ans));
	cout << SZ(ans) << endl;
	if (SZ(ans))
	{
		FOR (i, 0, SZ(ans) - 1)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}