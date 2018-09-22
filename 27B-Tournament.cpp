/*
	SubmissionId	:	4198976
	ContestId	:	27
	Index	:	B
	ProblemName	:	Tournament
	ProblemTags	:	['bitmasks', 'brute force', 'dfs and similar', 'greedy']
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
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)

int cnt[100], f[100], t, n;
bool mark[100];
vector<int> adj[100], ans;

void dfs(int v)
{
    mark[v] = true;
    t++;
    FOR (i, 0, SZ(adj[v]) - 1)
    {
        int u = adj[v][i];
        if (!mark[u])
            dfs(u);
    }
    t++;
    f[v] = t;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	FOR (i, 1, n * (n - 1) / 2 - 1)
	{
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        cnt[a]++;
        cnt[b]++;
	}
	FOR (i, 1, n)
        if (cnt[i] != n - 1)
            ans.pb(i);
	FOR (i, 1, n)
        if (!mark[i])
            dfs(i);
    if (f[ans[0]] > f[ans[1]])
        cout << ans[0] << " " << ans[1] << "\n";
    else
        cout << ans[1] << " " << ans[0] << "\n";
	return 0;
}
