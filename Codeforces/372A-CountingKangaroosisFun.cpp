/*
	SubmissionId	:	5429320
	ContestId	:	372
	Index	:	A
	ProblemName	:	Counting Kangaroos is Fun
	ProblemTags	:	['binary search', 'greedy', 'sortings', 'two pointers']
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
#define MAXN 500010

int n, a[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = n;
	int q = n / 2;
	FORD (p, n, 1)
	{
		while (q >= 1 && 2 * a[q] > a[p])
			q--;
		if (q == 0)
			break;
		else
		{
			ans--;
			q--;
		}
	}
	cout << ans << "\n";
	return 0;
}