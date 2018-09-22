/*
	SubmissionId	:	4040321
	ContestId	:	327
	Index	:	D
	ProblemName	:	Block Tower
	ProblemTags	:	['constructive algorithms', 'dfs and similar', 'graphs']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

//
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<fstream>
#include<sstream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)

struct Tri
{
    char c;
    int x, y;
};

Tri tri(char _c, int _x, int _y)
{
    Tri a;
    a.c = _c;
    a.x = _x;
    a.y = _y;
    return a;
}

int father[600][600];
int xx, yy;
char s[600][600];
int dx[] = {0, +1, 0, -1};
int dy[] = {-1, 0, +1, 0};
int deg[600][600];
bool mark[600][600];
vector<pii> leaves;
vector<Tri> ans;

void dfs(pii v)
{
    mark[v.X][v.Y] = true;
    FOR (i, 0, 3)
    {
        int x2 = v.X + dx[i];
        int y2 = v.Y + dy[i];
        if (s[x2][y2] == '.' && !mark[x2][y2])
        {
            father[x2][y2] = (i + 2) % 4;
            deg[v.X][v.Y]++;
            deg[x2][y2]++;
            dfs(mp(x2, y2));
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);
	memset(father, -1, sizeof father);
	cin >> yy >> xx;
	FOR (y, 1, yy)
        FOR (x, 1, xx)
            cin >> s[x][y];
    FOR (y, 1, yy)
        FOR (x, 1, xx)
            if (s[x][y] == '.' && !mark[x][y])
                dfs(mp(x, y));
    FOR (y, 1, yy)
        FOR (x, 1, xx)
            if (s[x][y] == '.' && deg[x][y] == 1)
                leaves.pb(mp(x, y));
    memset(mark, 0, sizeof mark);
    FOR (i, 0, SZ(leaves) - 1)
    {
        int x2, y2, x = leaves[i].X, y = leaves[i].Y;
        if (mark[x][y])
            continue;
        mark[x][y] = true;
        int j = father[x][y];
        if (j != -1)
        {
            x2 = x + dx[j];
            y2 = y + dy[j];
            deg[x2][y2]--;
            if (deg[x2][y2] == 1 && !mark[x2][y2])
                leaves.pb(mp(x2, y2));
            ans.pb(tri('B', x2, y2));
            ans.pb(tri('R', x, y));
            ans.pb(tri('D', x2, y2));
        }
    }
    FOR (y, 1, yy)
        FOR (x, 1, xx)
            if (s[x][y] == '.' && father[x][y] == -1)
                ans.pb(tri('B', x, y));
    cout << SZ(ans) << endl;
    FOR (i, 0, SZ(ans) - 1)
        cout << ans[i].c << " " << ans[i].y << " " << ans[i].x << endl;
	return 0;
}
