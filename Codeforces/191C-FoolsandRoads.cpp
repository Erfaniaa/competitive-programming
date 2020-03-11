/*
	SubmissionId	:	4719666
	ContestId	:	191
	Index	:	C
	ProblemName	:	Fools and Roads
	ProblemTags	:	['data structures', 'dfs and similar', 'trees']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

#define MAXLOGN 20
#define MAXN 100010

vector<pair<int, int> > adj[MAXN];
int par[MAXN][MAXLOGN + 1], n, q, dis[MAXN], add[MAXN], cnt, ans[MAXN];

void dfs(int v, int f, int d)
{
    dis[v] = d;
    par[v][0] = f;
    for (int i = 1; i <= MAXLOGN; i++)
        if (par[v][i - 1] == -1)
            par[v][i] = -1;
        else
            par[v][i] = par[par[v][i - 1]][i - 1];
    for (int i = 0; i < adj[v].size(); i++)
    {
        pair<int, int> u = adj[v][i];
        if (u.first != f)
            dfs(u.first, v, d + 1);
    }
}

inline int ancestor(int v, int k)
{
    int ret = v;
    for (int i = 0; i <= MAXLOGN; i++)
        if ((k >> i) & 1)
            ret = par[ret][i];
    return ret;
}

inline int lca(int v, int u)
{
    if (dis[v] < dis[u])
        swap(u, v);
    v = ancestor(v, dis[v] - dis[u]);
    if (v == u)
        return v;
    for (int i = MAXLOGN; i >= 0; i--)
        if (par[v][i] != par[u][i])
        {
            v = par[v][i];
            u = par[u][i];
        }
    return par[v][0];
}

int dfs2(int v, int f, int edge)
{
    int sum = 0;
    sum += add[v];
    for (int i = 0; i < adj[v].size(); i++)
    {
        pair<int, int> u = adj[v][i];
        if (u.first != f)
            sum += dfs2(u.first, v, u.second);
    }
    ans[edge] = sum;
    return sum;
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(pair<int, int>(v, i));
        adj[v].push_back(pair<int, int>(u, i));
    }
    cin >> q;
    dfs(1, -1, 0);
    for (int i = 0; i < q; i++)
    {
        int v, u, w;
        cin >> v >> u;
        w = lca(v, u);
        add[v]++;
        add[u]++;
        add[w] -= 2;
    }
    dfs2(1, -1, 0);
    for (int i = 1; i <= n - 1; i++)
        cout << ans[i] << " ";
    return 0;
}