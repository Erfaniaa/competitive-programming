/*
	SubmissionId	:	4137665
	ContestId	:	295
	Index	:	B
	ProblemName	:	Greg and Graph
	ProblemTags	:	['dp', 'graphs', 'shortest paths']
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
#define MAXN 510

ll d[MAXN][MAXN];
ll ans[MAXN];
int n, a[MAXN];

int main()
{
	ios::sync_with_stdio(false);
    cin >> n;
    FOR (i, 1, n)
        FOR (j, 1, n)
            cin >> d[i][j];
    FOR (i, 1, n)
        cin >> a[i];
    FORD (p, n, 1)
    {
        int k = a[p];
        FOR (i, 1, n)
            FOR (j, 1, n)
            {
                int u = a[i];
                int v = a[j];
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
            }
        ll sum = 0;
        FORD (i, n, p)
            FORD (j, n, p)
            {
                int u = a[i];
                int v = a[j];
                sum += d[u][v];
            }
        ans[p] = sum;
    }
    FOR (i, 1, n)
        cout << ans[i] << " ";
	return 0;
}
