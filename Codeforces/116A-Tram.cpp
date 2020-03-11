/*
	SubmissionId	:	6511460
	ContestId	:	116
	Index	:	A
	ProblemName	:	Tram
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

int n, cnt;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int ans = 0;
	FOR (i, 1, n)
	{
		int a, b;
		cin >> a >> b;
		cnt += b - a;
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}