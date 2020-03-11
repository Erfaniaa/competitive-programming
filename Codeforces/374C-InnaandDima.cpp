/*
	SubmissionId	:	5465927
	ContestId	:	374
	Index	:	C
	ProblemName	:	Inna and Dima
	ProblemTags	:	['dfs and similar', 'dp', 'graphs', 'implementation']
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
#define MAXN 3000

int mark[MAXN][MAXN];
int dx[] = {0, 0, -1, +1};
int dy[] = {-1, +1, 0, 0};
int xx, yy;
char a[MAXN][MAXN], next[300];
int dp[MAXN][MAXN];
bool haveCycle;

int dfs1(int x, int y)
{
	if (dp[x][y] != -1)
		return dp[x][y];
	int ret = 0;
	FOR (i, 0, 3)
	{
		int x2 = x + dx[i];
		int y2 = y + dy[i];
		if (a[x2][y2] == next[a[x][y]])
			ret = max(ret, dfs1(x2, y2));
	}
	if (a[x][y] == 'A')
		ret++;
	return dp[x][y] = ret;
}

int dfs2(int x, int y)
{
	mark[x][y] = 1;
	FOR (i, 0, 3)
	{
		int x2 = x + dx[i];
		int y2 = y + dy[i];
		if (a[x2][y2] == next[a[x][y]])
		{
			if (!mark[x2][y2])
				dfs2(x2, y2);
			if (mark[x2][y2] == 1)
				haveCycle = true;
		}
	}
	mark[x][y] = 2;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> yy >> xx;
	next['D'] = 'I';
	next['I'] = 'M';
	next['M'] = 'A';
	next['A'] = 'D';
	memset(dp, -1, sizeof dp);
	FOR (y, 1, yy)
		FOR (x, 1, xx)
			cin >> a[x][y];
	int ans = 0;
	FOR (y, 1, yy)
		FOR (x, 1, xx)
			if (!mark[x][y] && a[x][y] == 'D')
				dfs2(x, y);
	if (haveCycle)
	{
		cout << "Poor Inna!\n";
		return 0;
	}
	FOR (y, 1, yy)
		FOR (x, 1, xx)
			if (a[x][y] == 'D')
				ans = max(ans, dfs1(x, y));
	if (ans == 0)
		cout << "Poor Dima!\n";
	else
		cout << ans << "\n";
	return 0;
}