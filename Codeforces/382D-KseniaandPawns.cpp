/*
	SubmissionId	:	5724058
	ContestId	:	382
	Index	:	D
	ProblemName	:	Ksenia and Pawns
	ProblemTags	:	['dfs and similar', 'graphs', 'implementation', 'trees']
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
#define MAXN 2010

int mark[MAXN][MAXN], yy, xx, cnt;
bool haveCycle;
char a[MAXN][MAXN];
pair<int, pii> d[MAXN][MAXN];

int dx(char &c)
{
	if (c == '<')
		return -1;
	if (c == '>')
		return 1;
	if (c == '^')
		return 0;
	if (c == 'v')
		return 0;
	return 0;
}

int dy(char &c)
{
	if (c == '<')
		return 0;
	if (c == '>')
		return 0;
	if (c == '^')
		return -1;
	if (c == 'v')
		return 1;
	return 0;
}

void dfs1(int x, int y)
{
	mark[x][y] = 1;
	if (!mark[x + dx(a[x][y])][y + dy(a[x][y])] && a[x + dx(a[x][y])][y + dy(a[x][y])] != '#')
		dfs1(x + dx(a[x][y]), y + dy(a[x][y]));
	if (mark[x + dx(a[x][y])][y + dy(a[x][y])] == 1)
		haveCycle = true;
	mark[x][y] = 2;
}

int dfs2(int x, int y)
{
	if (a[x][y] == '#')
		return 0;
	if (d[x][y].X)
		return d[x][y].X;
	if (a[x + dx(a[x][y])][y + dy(a[x][y])] == '#')
	{
		d[x][y] = make_pair(1, pii(x, y));
		return 1;
	}
	else
	{
		d[x][y].X = dfs2(x + dx(a[x][y]), y + dy(a[x][y])) + 1;
		d[x][y].Y = d[x + dx(a[x][y])][y + dy(a[x][y])].Y;
		return d[x][y].X;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> yy >> xx;
	FOR (y, 1, yy)
		FOR (x, 1, xx)
		{
			cin >> a[x][y];
			if (a[x][y] != '#')
				cnt++;
		}
	if (cnt <= 1)
	{
		cout << 0 << endl;
		return 0;
	}
	FOR (y, 1, yy)
		FOR (x, 1, xx)
			if (a[x][y] != '#')
			{
				if (!mark[x][y])
					dfs1(x, y);
				if (haveCycle)
				{
					cout << -1 << endl;
					return 0;
				}
			}
	int maxDis = 0;
	pii p;
	FOR (y, 1, yy)
		FOR (x, 1, xx)
			if (a[x][y] != '#')
			{
				dfs2(x, y);
				if (d[x][y].X > maxDis)
				{
					maxDis = d[x][y].X;
					p = d[x][y].Y;
				}
			}
	bool flag = false;
	FOR (y, 1, yy)
		FOR (x, 1, xx)
			if (a[x][y] != '#')
			{
				dfs2(x, y);
				if (d[x][y].X == maxDis && d[x][y].Y != p)
				{
					flag = true;
					break;
				}
			}
	if (flag)
		cout << 2 * maxDis << endl;
	else
		cout << 2 * maxDis - 1 << endl;
	return 0;
}