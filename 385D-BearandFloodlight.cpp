/*
	SubmissionId	:	5814110
	ContestId	:	385
	Index	:	D
	ProblemName	:	Bear and Floodlight
	ProblemTags	:	['bitmasks', 'dp', 'geometry']
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
#define MAXN 21

double dp[1 << MAXN], l, r, ans;
int n;

struct Light
{
	double x, y;
	double alpha;
	Light(double _x = 0, double _y = 0, double _alpha = 0)
	{
		x = _x;
		y = _y;
		alpha = _alpha;
	}
} p[MAXN];

double calc(int idx, double s)
{
	double beta = p[idx].alpha - atan2(p[idx].x - s, p[idx].y);
	if (beta >= M_PI_2)
		return r;
	return p[idx].x + tan(beta) * p[idx].y;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l >> r;
	FOR (i, 0, n - 1)
	{
		cin >> p[i].x >> p[i].y >> p[i].alpha;
		p[i].alpha *= M_PI / 180.0;
	}
	FOR (mask, 0, (1 << n) - 1)
	{
		dp[mask] = l;
		FOR (i, 0, n - 1)
		{
			if (mask & (1 << i))
			{
				int mask2 = mask - (1 << i);
				dp[mask] = max(dp[mask], calc(i, dp[mask2]));
			}
			ans = max(ans, dp[mask] - l);
		}
	}
	cout.precision(9);
	cout << fixed << min(ans, r - l) << endl;
	return 0;
}