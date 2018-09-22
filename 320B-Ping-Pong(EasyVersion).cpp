/*
	SubmissionId	:	3945922
	ContestId	:	320
	Index	:	B
	ProblemName	:	Ping-Pong (Easy Version)
	ProblemTags	:	['dfs and similar', 'graphs']
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
#define Size(x) ((int)((x).size()))
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)

bool rangeCheck(int a, pii b)
{
    if (a < b.Y && a > b.X)
        return true;
    else
        return false;
}

bool canMove(pii x, pii y)
{
    if (rangeCheck(x.X, y) || rangeCheck(x.Y, y))
        return true;
    else
        return false;
}

int n;
vector<pii> inter;
vector<int> neighbor[200];
int mark[200];

void dfs(int v, int color)
{
    mark[v] = color;
    FOR (i, 0, Size(neighbor[v]) - 1)
        if (mark[neighbor[v][i]] == 0)
            dfs(neighbor[v][i], color);
}

int main()
{
    cin >> n;
    FOR (i, 1, n)
    {
        int q, a, b;
        cin >> q >> a >> b;
        if (q == 1)
        {
            inter.pb(mp(a, b));
            FOR (j, 0, Size(inter) - 2)
            {
                if (canMove(inter[j], mp(a, b)))
                    neighbor[j].pb(Size(inter) - 1);
                if (canMove(mp(a, b), inter[j]))
                    neighbor[Size(inter) - 1].pb(j);
            }
        }
        if (q == 2)
        {
            a--;
            b--;
            FOR (j, 0, Size(inter) - 1)
                mark[j] = 0;
            dfs(a, 1);
            if (mark[b] == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
	return 0;
}
