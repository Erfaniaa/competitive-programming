/*
	SubmissionId	:	4715085
	ContestId	:	208
	Index	:	E
	ProblemName	:	Blood Cousins
	ProblemTags	:	['binary search', 'data structures', 'dfs and similar', 'trees']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAXN 100010

int n, now, father[MAXN], dis[MAXN], q, v, k, start[MAXN], finish[MAXN];
vector <int> adj[MAXN], levelStart[MAXN], levelVertex[MAXN];

void dfs(int v, int d)
{
    levelStart[d].push_back(now);
    levelVertex[d].push_back(v);
    dis[v] = d;
    start[v] = now++;
    for (int i = 0; i < adj[v].size(); i++)
        dfs(adj[v][i], d + 1);
    finish[v] = now;
}

int ancestor(int v, int k)
{
    int l = dis[v] - k;
    if (l < 0)
        return -1;
    int idx = lower_bound(levelStart[l].begin(), levelStart[l].end(), start[v]) - 1 - levelStart[l].begin();
    if (levelVertex[l][idx] == 0)
        return -1;
    return levelVertex[l][idx];
}

int solve(int v, int p)
{
    int u = ancestor(v, p);
    if (u == -1)
        return 1;
    int l = dis[v];
    int i = lower_bound(levelStart[l].begin(), levelStart[l].end(), start[u]) - levelStart[l].begin();
    int j = upper_bound(levelStart[l].begin(), levelStart[l].end(), finish[u]) - levelStart[l].begin();
    return j - i;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        adj[a].push_back(i);
        father[i] = a;
    }
    dfs(0, 0);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> v >> k;
        cout << solve(v, k) - 1 << " ";
    }
    return 0;
}
