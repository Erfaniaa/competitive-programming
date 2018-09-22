/*
	SubmissionId	:	4200063
	ContestId	:	27
	Index	:	D
	ProblemName	:	Ring Road 2
	ProblemTags	:	['2-sat', 'dfs and similar', 'dsu', 'graphs']
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
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 110

int n, m;
vector<pii> v;
bool mark[MAXN];
int ans[MAXN];

bool intersect(pii a, pii b)
{
    if (b.X > a.X && b.X < a.Y && b.Y > a.Y)
        return true;
    if (a.X > b.X && a.X < b.Y && a.Y > b.Y)
        return true;
    return false;
}

int dfs(int idx, int color)
{
    int x = v[idx].X;
    int y = v[idx].Y;
    mark[idx] = true;
    ans[idx] = color;
    FOR (i, 0, m - 1)
    {
        if (intersect(v[idx], v[i]) && ans[i] == color)
        {
            cout << "Impossible" << endl;
            exit(0);
        }
        if (!mark[i] && intersect(v[idx], v[i]))
            dfs(i, (color + 1) % 2);
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	FOR (i, 1, m)
	{
        int a, b;
        cin >> a >> b;
        v.pb(mp(min(a, b), max(a, b)));
    }
    memset(ans, -1, sizeof ans);
    FOR (i, 0, m - 1)
        if (!mark[i])
            dfs(i, 0);
    FOR (i, 0, m - 1)
        if (ans[i])
            cout << 'i';
        else
            cout << 'o';
    cout << endl;
	return 0;
}
