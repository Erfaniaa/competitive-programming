/*
	SubmissionId	:	4076465
	ContestId	:	25
	Index	:	D
	ProblemName	:	Roads not only in Berland
	ProblemTags	:	['dsu', 'graphs', 'trees']
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
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define MAXN 1001

bool mark[MAXN], used[MAXN][MAXN];
vector<pii> cycleEdges;
vector<int> comps, adj[MAXN], trees;
int n;

void dfs(int v, int father, int lastV)
{
    mark[v] = true;
    FOR (i, 0, SZ(adj[v]) - 1)
        if (!mark[adj[v][i]])
            dfs(adj[v][i], father, v);
        else
        if (adj[v][i] != lastV && !used[adj[v][i]][v])
        {
            used[v][adj[v][i]] = true;
            cycleEdges.pb(mp(v, adj[v][i]));
        }
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	FOR (i, 1, n - 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    FOR (i, 1, n)
        if (!mark[i])
        {
            comps.pb(i);
            dfs(i, i, i);
        }
    cout << SZ(cycleEdges) << endl;
    FOR (i, 0, SZ(cycleEdges) - 1)
        cout << cycleEdges[i].X << " " << cycleEdges[i].Y << " " << comps[i] << " " << comps[i + 1] << endl;
	return 0;
}
