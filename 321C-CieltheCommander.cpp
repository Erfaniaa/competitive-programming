/*
	SubmissionId	:	4640417
	ContestId	:	321
	Index	:	C
	ProblemName	:	Ciel the Commander
	ProblemTags	:	['constructive algorithms', 'dfs and similar', 'divide and conquer', 'greedy', 'trees']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<memory.h>

using namespace std;

#define MAXN 1000010
#define SZ(x) ((int)((x).size()))

int dp[MAXN], n;
bool mark[MAXN];
char ans[MAXN];
vector<int> adj[MAXN];
int centroidNum;

void centroid(int v, int f, int sz)
{
    //mark[v] = true;
    dp[v] = 1;
    bool isCentroid = true;
   //cout << "v: " << v << endl;
    for (int i = 0; i < SZ(adj[v]); i++)
    {
        int u = adj[v][i];
        if (!mark[u] && u != f)
        {
            centroid(u, v, sz);
            dp[v] += dp[u];
            if (dp[u] > sz / 2)
                isCentroid = false;
            //cout << u << " * " << dp[u] << endl;
        }
    }
    //cout << v << " " << dp[v] << " " << isCentroid << endl;
    if (isCentroid == true && ((sz - dp[v]) <= (sz / 2)))
    {
        centroidNum = v;
    }
}

int getSize(int v, int f)
{
    int sum = 1;
    for (int i = 0; i < SZ(adj[v]); i++)
    {
        int u = adj[v][i];
        if (u != f && !mark[u])
            sum += getSize(u, v);
    }
    return sum;
}

void solve(int v, int f, int sz, char r)
{
    //cout << v << " " << f << " " << sz << endl;
    if (sz == 1)
    {
        ans[v] = r;
        return;
    }
    centroidNum = -1;
    centroid(v, v, sz);
    int c = centroidNum;
    mark[c] = true;
    ans[c] = r;
    //cout << "Centroid: " << c << endl;
    //cin.get();
    for (int i = 0; i < SZ(adj[c]); i++)
    {
        int u = adj[c][i];
        if (u != f)
            solve(u, c, (getSize(u, c)), r + 1);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(1, -1, n, 'A');
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}
