/*
	SubmissionId	:	6511443
	ContestId	:	231
	Index	:	A
	ProblemName	:	Team
	ProblemTags	:	['brute force', 'greedy']
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

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int ans = 0;
	FOR (i, 1, n)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a + b + c >= 2)
			ans++;
	}
	cout << ans << endl;
	return 0;
}