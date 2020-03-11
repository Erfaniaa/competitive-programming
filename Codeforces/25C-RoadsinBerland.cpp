/*
	SubmissionId	:	4076270
	ContestId	:	25
	Index	:	C
	ProblemName	:	Roads in Berland
	ProblemTags	:	['graphs', 'shortest paths']
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

int n, q;
int dis[301][301];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	FOR (i, 1, n)
        FOR (j, 1, n)
            cin >> dis[i][j];
    cin >> q;
    FOR (p, 1, q)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = dis[u][v];
        int k = u;
        FOR (i, 1, n)
            FOR (j, 1, n)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        k = v;
        FOR (i, 1, n)
            FOR (j, 1, n)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        ll sum = 0;
        FOR (i, 1, n)
            FOR (j, 1, n)
                sum += dis[i][j];
        cout << sum / 2 << " ";
    }
	return 0;
}
