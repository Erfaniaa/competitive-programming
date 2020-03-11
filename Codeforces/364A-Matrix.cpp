/*
	SubmissionId	:	5159100
	ContestId	:	364
	Index	:	A
	ProblemName	:	Matrix
	ProblemTags	:	['combinatorics', 'data structures', 'implementation']
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
#define MAXN 10010

ll sum[MAXN], a;
map<ll, ll> cnt;

ll ans;
string s;

int main()
{
	cin >> a;
	cin >> s;
	FOR (i, 0, SZ(s) - 1)
		sum[i + 1] = sum[i] + (ll)(s[i] - '0');
	FOR (i, 1, SZ(s))
		FOR (j, i, SZ(s))
		{
			ll tmp = sum[j] - sum[i - 1];
			cnt[tmp]++;
		}
	if (a != 0)
	{
		FOR (i, 1, SZ(s))
			FOR (j, i, SZ(s))
			{
				ll tmp = sum[j] - sum[i - 1];
				if (tmp != 0)
					if (a % tmp == 0)
						ans += cnt[a / tmp];
			}
	}
	else
	{
		FOR (i, 1, SZ(s))
			FOR (j, i, SZ(s))
			{
				ll tmp = sum[j] - sum[i - 1];
				if (tmp == 0)
					ans += (ll)(SZ(s)) * (ll)(SZ(s) + 1) / 2;
				else
					ans += cnt[0];
			}
	}
	cout << ans << endl;
	return 0;
}