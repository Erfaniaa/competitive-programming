/*
	SubmissionId	:	4336250
	ContestId	:	144
	Index	:	D
	ProblemName	:	Missile Silos
	ProblemTags	:	['data structures', 'dfs and similar', 'graphs', 'shortest paths']
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
#define MAXN 100010
#define INF 1000000000

struct Node
{
    int idx, dis;
    Node (int _idx, int _dis)
    {
        idx = _idx;
        dis = _dis;
    }
    bool operator < (Node n) const
    {
        if (dis == n.dis)
            return idx < n.idx;
        return dis < n.dis;
    }
};

struct Edge
{
    int x, y, w;
    Edge (int _x, int _y, int _w)
    {
        x = _x;
        y = _y;
        w = _w;
    }
};

int n, m, s, dis[MAXN];
vector<pii> adj[MAXN];
vector<Edge> edges;
set<Node> nodes;
bool mark[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> s;
    FOR (i, 0, m - 1)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].pb(mp(y, w));
        adj[y].pb(mp(x, w));
        edges.pb(Edge(x, y, w));
    }
    FOR (i, 1, n)
        if (i != s)
        {
            //nodes.insert(Node(i, INF));
            dis[i] = INF;
        }
    nodes.insert(Node(s, 0));
    while (SZ(nodes))
    {
        Node v = *nodes.begin();
        nodes.erase(v);
        //mark[v.idx] = true;
        FOR (j, 0, SZ(adj[v.idx]) - 1)
        {
            pii e = adj[v.idx][j];
            if (/*!mark[e.X] && */dis[e.X] > v.dis + e.Y)
            {
                nodes.erase(Node(e.X, dis[e.X]));
                dis[e.X] = v.dis + e.Y;
                nodes.insert(Node(e.X, dis[e.X]));
            }
        }
    }
    int l, ans = 0;
    cin >> l;
    FOR (i, 1, n)
        if (dis[i] == l)
            ans++;
    FOR (i, 0, m - 1)
    {
        Edge e = edges[i];
        int d1 = dis[e.x];
        int d2 = dis[e.y];
        if (d1 > d2)
            swap(d1, d2);
        /*int x = e.w + d2 + d1;
        if (e.w > 1)
        {
            if (d1 + e.w == d2)
            {
                if (d1 < l && l < d2)
                    ans++;
                continue;
            }
            if (d1 < l && 2 * l < x)
                ans++;
            if (d2 < l && 2 * l < x)
                ans++;
            if (d1 < l && d2 <= l && 2 * l == x)
                ans++;
        }*/
        FOR (x, 1, e.w - 1)
        {
            int d = min(x + d1, e.w - x + d2);
            if (d == l)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}