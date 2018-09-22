/*
	SubmissionId	:	5751323
	ContestId	:	383
	Index	:	A
	ProblemName	:	Milking cows
	ProblemTags	:	['data structures', 'greedy']
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
#define MAXN 200010

int a[MAXN], s[MAXN], n;
ll ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
	{
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	FOR (i, 1, n)
		if (a[i])
			ans += (ll)((n - i) - (s[n] - s[i]));
	cout << ans << endl;
	return 0;
}