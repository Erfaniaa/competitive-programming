/*
	SubmissionId	:	5734719
	ContestId	:	160
	Index	:	D
	ProblemName	:	Edges in MST
	ProblemTags	:	['dfs and similar', 'dsu', 'graphs', 'sortings']
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
#define debug(x) cerr << #x << " = " << x << '\n'
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define MAXN 100010

struct Edge
{
    int x, y, w, idx;
    bool operator < (Edge e) const
    {
        return w < e.w;
    }
};

int father[MAXN], dis[MAXN], backEdge[MAXN], ans[MAXN], size[MAXN], m, n;
bool mark[MAXN];
vector<pii> adj[MAXN];
Edge edges[MAXN];

int find(int x)
{
    if (father[x] == x)
        return x;
    return find(father[x]);
}

void merge(Edge e)
{
    int x = find(e.x);
    int y = find(e.y);
    if (x != y)
    {
        if (size[x] > size[y])
            swap(x, y);
        father[x] = y;
        size[y] += size[x];
    }
}

int dfs(int v, int edgeIdx, int d)
{
    mark[v] = 1;
    dis[v] = d;
    if (backEdge[v])
        return backEdge[v];
    backEdge[v] = d;
    FOR (i, 0, SZ(adj[v]) - 1)
    {
        pii u = adj[v][i];
        if (mark[u.X] == 1 && u.Y != edgeIdx)
        {
            backEdge[v] = min(backEdge[v], dis[u.X]);
            ans[u.Y] = 1;
        }
        if (!mark[u.X])
            backEdge[v] = min(backEdge[v], dfs(u.X, u.Y, d + 1));
    }
    if (edgeIdx != -1)
    {
        if (backEdge[v] < d)
            ans[edgeIdx] = 1;
        else
            ans[edgeIdx] = 2;
    }
    mark[v] = 2;
    return backEdge[v];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    FOR (i, 0, m - 1)
    {
        cin >> edges[i].x >> edges[i].y >> edges[i].w;
        edges[i].idx = i;
    }
    FOR (i, 0, n)
    {
        father[i] = i;
        size[i] = 1;
    }
    sort(edges, edges + m);
    vector<int> nodes;
    int x, y;
    FOR (i, 0, m - 1)
    {
        x = find(edges[i].x);
        y = find(edges[i].y);
        nodes.clear();
        int l = i;
        if (x != y)
        {
            adj[x].pb(mp(y, edges[i].idx));
            adj[y].pb(mp(x, edges[i].idx));
            nodes.pb(x);
            nodes.pb(y);
            mark[x] = mark[y] = 0;
            backEdge[x] = backEdge[y] = 0;
        }
        while (i < m - 1 && edges[i].w == edges[i + 1].w)
        {
            i++;
            x = find(edges[i].x);
            y = find(edges[i].y);
            if (x != y)
            {
                adj[x].pb(mp(y, edges[i].idx));
                adj[y].pb(mp(x, edges[i].idx));
                nodes.pb(x);
                nodes.pb(y);
                mark[x] = mark[y] = 0;
                backEdge[x] = backEdge[y] = 0;
            }
        }
        int r = i;
        FOR (j, 0, SZ(nodes) - 1)
            if (!mark[nodes[j]])
                dfs(nodes[j], -1, 1);
        FOR (j, 0, SZ(nodes) - 1)
            adj[nodes[j]].clear();
        FOR (j, l, r)
            merge(edges[j]);
    }
    FOR (i, 0, m - 1)
        if (!ans[i])
            cout << "none" << '\n';
        else
            if (ans[i] == 2)
                cout << "any" << '\n';
            else
                cout << "at least one" << '\n';
    return 0;
}
