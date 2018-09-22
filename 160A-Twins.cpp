/*
	SubmissionId	:	6511848
	ContestId	:	160
	Index	:	A
	ProblemName	:	Twins
	ProblemTags	:	['greedy', 'sortings']
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

int n, a[101], sum, sum2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	FOR (i, 1, n)
	{
		sum2 += a[i];
		if (2 * sum2 > sum)
		{
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}