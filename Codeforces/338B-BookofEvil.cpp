/*
	SubmissionId	:	5414758
	ContestId	:	338
	Index	:	B
	ProblemName	:	Book of Evil
	ProblemTags	:	['dfs and similar', 'dp', 'trees']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

#define pii pair<int, int>
#define X first
#define Y second
#define pb push_back
#define SZ(x) ((int)((x).size()))
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

pii maxDis[MAXN][2];
vector<int> adj[MAXN];
bool isBad[MAXN];
int n, m, d;

inline pii dfs1(int v, int f)
{
    maxDis[v][0] = maxDis[v][1] = pii(-INF, -1);
    if (isBad[v])
        maxDis[v][0] = pii(0, v);
    FOR (i, 0, SZ(adj[v]) - 1)
    {
        int u = adj[v][i];
        if (u != f)
        {
            pii p = dfs1(u, v);
            p.X++;
            p.Y = u;
            if (p.X >= maxDis[v][0].X)
            {
                maxDis[v][1] = maxDis[v][0];
                maxDis[v][0] = p;
            }
            else if (p.X >= maxDis[v][1].X)
                maxDis[v][1] = p;
        }
    }
    return maxDis[v][0];
}

inline void dfs2(int v, int f)
{
    if (f != -1)
    {
        pii p1 = maxDis[f][0];
        pii p2 = maxDis[f][1];
        p1.X++;
        p2.X++;
        if (p1.Y != v)
        {
            if (p1.X >= maxDis[v][0].X)
                {
                    maxDis[v][1] = maxDis[v][0];
                    maxDis[v][0] = p1;
                }
                else if (p1.X >= maxDis[v][1].X)
                    maxDis[v][1] = p1;
        }
        if (p2.Y != v)
        {
            if (p2.X >= maxDis[v][0].X)
                {
                    maxDis[v][1] = maxDis[v][0];
                    maxDis[v][0] = p2;
                }
                else if (p2.X >= maxDis[v][1].X)
                    maxDis[v][1] = p2;
        }
    }
    FOR (i, 0, SZ(adj[v]) - 1)
    {
        int u = adj[v][i];
        if (u != f)
            dfs2(u, v);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> d;
    FOR (i, 1, m)
    {
        int a;
        cin >> a;
        isBad[a] = true;
    }
    FOR (i, 1, n - 1)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    int cnt = 0;
    FOR (i, 1, n)
        if (maxDis[i][0].X <= d)
            cnt++;
    cout << cnt << "\n";
    return 0;
}