/*
	SubmissionId	:	13608238
	ContestId	:	547
	Index	:	D
	ProblemName	:	Mike and Fish
	ProblemTags	:	['dfs and similar', 'graphs']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF (1000 * 1000 * 1000)
#define MAXN 200010

int x[MAXN + 1], y[MAXN + 1], n;
unordered_map<int, int> edges[2 * MAXN + 10];
vector<int> odds;
set<int> node[2 * MAXN + 10];

inline void dfs(int v)
{
    if (SZ(node[v]) == 0)
        return;
    int u = *(node[v].begin());
    node[v].erase(u);
    node[u].erase(v);
    edges[v][u] = edges[u][v] = (u > MAXN) + 1;
    dfs(u);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        node[x[i]].insert(MAXN + y[i]);
        node[MAXN + y[i]].insert(x[i]);
    }
    for (int i = 1; i <= 2 * MAXN; i++)
        if (SZ(node[i]) % 2 == 1)
            odds.push_back(i);
    for (int i = 0; i < SZ(odds); i += 2)
    {
        node[odds[i]].insert(odds[i + 1]);
        node[odds[i + 1]].insert(odds[i]);
    }
    for (int i = 1; i <= n; i++)
        dfs(x[i]);
    char ans[] = {'-', 'b', 'r'};
    for (int i = 1; i <= n; i++)
        cout << ans[edges[x[i]][y[i] + MAXN]];
    return 0;
}