/*
	SubmissionId	:	4639531
	ContestId	:	346
	Index	:	D
	ProblemName	:	Robot Control
	ProblemTags	:	['shortest paths']
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

set<int> q, temp;
vector<int> adj[MAXN];
int ans[MAXN], deg[MAXN];
int n, m, s, t, cnt;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        deg[a]++;
    }
    cin >> s >> t;
    memset(ans, -1, sizeof ans);
    q.insert(t);
    ans[t] = 0;
    while (SZ(q) + SZ(temp) > 0)
    {
        if (SZ(q) == 0)
        {
            q = temp;
            temp.clear();
            cnt++;
        }
        int v = *(q.begin());
        q.erase(v);
        deg[v] = 0;
        ans[v] = cnt;
        if (v == s)
            break;
        for (int i = 0; i < SZ(adj[v]); i++)
        {
            if (deg[adj[v][i]] > 0)
            {
                deg[adj[v][i]]--;
                if (deg[adj[v][i]] == 0)
                {
                    q.insert(adj[v][i]);
                    temp.erase(adj[v][i]);
                }
                else
                    temp.insert(adj[v][i]);
            }
        }
    }
    cout << ans[s] << endl;
    return 0;
}
