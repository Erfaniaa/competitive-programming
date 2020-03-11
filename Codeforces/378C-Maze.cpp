/*
	SubmissionId	:	5558972
	ContestId	:	378
	Index	:	C
	ProblemName	:	Maze
	ProblemTags	:	['dfs and similar']
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
#define MAXN 600

int dx[] = {0, 0, -1, +1};
int dy[] = {-1, +1, 0, 0};

char a[MAXN][MAXN];
vector<pii> level[MAXN * MAXN + 10];
bool mark[MAXN][MAXN];
int xx, yy, k;

void dfs(int x, int y, int d)
{
	mark[x][y] = true;
	level[d].pb(pii(x, y));
	FOR (i, 0, 3)
	{
		int x2 = x + dx[i];
		int y2 = y + dy[i];
		if (x2 >= 1 && x2 <= xx && y2 >= 1 && y2 <= yy && a[x2][y2] == '.' && !mark[x2][y2])
			dfs(x2, y2, d + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> yy >> xx >> k;
	FOR (y, 1, yy)
		FOR (x, 1, xx)
			cin >> a[x][y];
	bool flag = false;
	FOR (y, 1, yy)
		FOR (x, 1, xx)
			if (!flag && a[x][y] == '.')
			{
				dfs(x, y, 0);
				flag = true;
			}
	FORD (i, MAXN * MAXN, 0)
		FOR (j, 0, SZ(level[i]) - 1)
		{
			pii p = level[i][j];
			if (k > 0)
			{
				k--;
				a[p.X][p.Y] = 'X';
			}
			else
				break;
		}
	FOR (y, 1, yy)
	{
		FOR (x, 1, xx)
			cout << a[x][y];
		cout << endl;
	}
	return 0;
}