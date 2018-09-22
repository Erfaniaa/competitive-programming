/*
	SubmissionId	:	5106508
	ContestId	:	362
	Index	:	A
	ProblemName	:	Two Semiknights Meet
	ProblemTags	:	['greedy', 'math']
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
#define MAXN 10

int dx[4] = {-2, +2, -2, +2};
int dy[4] = {-2, +2, +2, -2};
bool mark[MAXN][MAXN][2][201];

struct Tri
{
	int X, Y, T;
	Tri (int _X, int _Y, int _T)
	{
		X = _X;
		Y = _Y;
		T = _T;
	}
};

void bfs(int x, int y, int num)
{
	vector<Tri> q;
	q.pb(Tri(x, y, 0));
	FOR (i, 0, SZ(q) - 1)
	{
		Tri v = q[i];
		mark[v.X][v.Y][num][v.T] = true;
		FOR (j, 0, 3)
		{
			Tri u = Tri(v.X + dx[j], v.Y + dy[j], v.T + 1);
			if (u.X >= 1 && u.X <= 8 && u.Y >= 1 && u.Y <= 8 && u.T <= 200)
				if (!mark[u.X][u.Y][num][u.T])
				{
					mark[u.X][u.Y][num][u.T] = true;
					q.pb(u);
				}
		}
	}
}

int t;
char a[MAXN][MAXN];

int main()
{
	cin >> t;
	int cnt;
	bool ans;
	FOR (i, 1, t)
	{
		cnt = 0;
		memset(mark, 0, sizeof mark);
		FOR (y, 1, 8)
			FOR (x, 1, 8)
			{
				cin >> a[x][y];
				if (a[x][y] == 'K')
				{
					bfs(x, y, cnt);
					cnt++;
				}
			}
		ans = false;
		FOR (y, 1, 8)
			if (!ans)
				FOR (x, 1, 8)
					if (!ans && a[x][y] != '#')
						FOR (tm, 0, 200)
							if (mark[x][y][0][tm] && mark[x][y][1][tm])
							{
								ans = true;
								break;
							}
		if (cnt == 1)
			ans = true;
		if (ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}