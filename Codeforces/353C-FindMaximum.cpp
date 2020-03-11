/*
	SubmissionId	:	4729777
	ContestId	:	353
	Index	:	C
	ProblemName	:	Find Maximum
	ProblemTags	:	['implementation', 'math', 'number theory']
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
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

int a[MAXN], n, sum[MAXN], s[MAXN];

int solve(int idx)
{
	if (idx == 0)
		return 0;
	int ret = 0;
	if (s[idx] == 0)
		return solve(idx - 1);
	ret = max(sum[idx - 1], a[idx] + solve(idx - 1));
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
		cin >> a[i];
	FOR (i, 1, n)
		sum[i] = a[i] + sum[i - 1];
	FOR (i, 1, n)
	{
		char ch;
		cin >> ch;
		s[i] = (int)ch - 48;
	}
	cout << solve(n) << endl;
	return 0;
}