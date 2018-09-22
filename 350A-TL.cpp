/*
	SubmissionId	:	4632004
	ContestId	:	350
	Index	:	A
	ProblemName	:	TL
	ProblemTags	:	['brute force', 'greedy', 'implementation']
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
#define mp make_pair
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 10000

int n, m, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int minA = MAXN;
	int maxA = -1;
	FOR (i, 1, n)
	{
		int a;
		cin >> a;
		minA = min(minA, a);
		maxA = max(maxA, a);
	}
	ans = max(maxA, 2 * minA);
	FOR (i, 1, m)
	{
		int a;
		cin >> a;
		if (a <= ans)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}