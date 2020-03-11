/*
	SubmissionId	:	5272441
	ContestId	:	85
	Index	:	E
	ProblemName	:	Guard Towers
	ProblemTags	:	['binary search', 'dsu', 'geometry', 'graphs', 'sortings']
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
#define MOD (1000 * 1000 * 1000 + 7)
#define MAXN 5010

int x[MAXN], y[MAXN], color[MAXN], n, k, dis[MAXN][MAXN];

inline int abs2(int x)
{
	if (x >= 0)
		return x;
	else
		return -x;
}

void dfs(int v, int c, int w)
{
	color[v] = c;
	FOR (i, 1, n)
		if (i != v && dis[v][i] > w)
		{
			if (color[i] == -1)
				dfs(i, 1 - c, w);
			else
				if (color[i] == c)
					throw 1;
		}
}

bool check(int x)
{
	FOR (i, 1, n)
        color[i] = -1;
	FOR (i, 1, n)
		if (color[i] == -1)
		{
			try
			{
				dfs(i, 0, x);
			}
			catch (int err)
			{
				return false;
			}
		}
	return true;
}

int search()
{
	int l = 0;
	int r = 2 * MAXN;
	int ret = 2 * MAXN;
	while (l < r)
	{
		int m = (l + r) / 2;
		if (check(m))
		{
			ret = min(m, ret);
			r = m;
		}
		else
			l = m + 1;
	}
	if (check(l))
        ret = min(ret, l);
	return ret;
}

ll cnt(int x)
{
	ll ret = 1;
	memset(color, -1, sizeof color);
	FOR (i, 1, n)
		if (color[i] == -1)
		{
			try
			{
				dfs(i, 0, x);
				ret = (2 * ret) % MOD;
			}
			catch (int err)
			{
			}
		}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
		cin >> x[i] >> y[i];
	FOR (i, 1, n)
		FOR (j, 1, n)
			dis[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
	int ans = search();
	cout << ans << endl << cnt(ans) << endl;
	return 0;
}
