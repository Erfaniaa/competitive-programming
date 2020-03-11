/*
	SubmissionId	:	6511617
	ContestId	:	119
	Index	:	A
	ProblemName	:	Epic Game
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++0x
	Verdict	:	OK
*/

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
#define MAXN 100010

int a[2], n, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a[0] >> a[1] >> n;
	int ans = 1;
	while (n >= __gcd(n, a[1 - ans]))
	{
		n -= __gcd(n, a[1 - ans]);
		ans = 1 - ans;
	}
	cout << ans << endl;
	return 0;
}