/*
	SubmissionId	:	4710395
	ContestId	:	54
	Index	:	C
	ProblemName	:	First Digit Law
	ProblemTags	:	['dp', 'math', 'probabilities']
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
#define MAXN 1010

int countDigits(ll x)
{
	int ret = 0;
	while (x > 0)
	{
		ret++;
		x /= 10;
	}
	return ret;
}

ll haveOne(ll x)
{
	if (x == 0)
		return 0;
	ll digCnt = countDigits(x);
	ll ret = 0;
	ll tmp = 1;
	FOR (i, 1, digCnt - 1)
	{
		ret = ret * 10 + 1;
		tmp *= 10;
	}
	ll y = x;
	while (y > 9)
		y /= 10;
	if (y == 1)
		ret += x - tmp + 1;
	else
		ret = ret * 10 + 1;
	return ret;
}

ll l, r;
int n, k;
long double p[MAXN], d[MAXN][MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
	{
		cin >> l >> r;
		p[i] = (long double)(haveOne(r) - haveOne(l - 1)) / (long double)(r - l + 1);
	}
	cin >> k;
	int x = ceil(n * k / 100.0);
	FOR (i, 1, n)
		d[i][0] = 1;
	d[1][1] = p[1];
	FOR (i, 2, n)
		FOR (j, 1, x)
			d[i][j] = p[i] * d[i - 1][j - 1] + (1 - p[i]) * d[i - 1][j];
	cout.precision(12);
	cout << fixed << d[n][x] << endl;
	return 0;
}