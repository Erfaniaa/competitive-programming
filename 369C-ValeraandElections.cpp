/*
	SubmissionId	:	5300924
	ContestId	:	369
	Index	:	C
	ProblemName	:	Valera and Elections
	ProblemTags	:	['dfs and similar', 'graphs', 'trees']
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
#include<fstream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

vector<pii> adj[MAXN];
int n;
vector<int> ans;
bool isRepaired;

int dfs1(int v, int f, int p)
{
	int sum = 0;
	FOR (i, 0, SZ(adj[v]) - 1)
	{
		pii u = adj[v][i];
		if (u.X != f)
			sum += dfs1(u.X, v, u.Y);
	}
	if (sum == 0 && p == 2)
		ans.pb(v);
	if (p == 2)
		return sum + 1;
	else
		return sum;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n - 1)
	{
		int x, y, p;
		cin >> x >> y >> p;
		adj[x].pb(pii(y, p));
		adj[y].pb(pii(x, p));
	}
	dfs1(1, 0, 1);
	cout << SZ(ans) << endl;
	FOR (i, 0, SZ(ans) - 1)
		cout << ans[i] << " ";
	//cout << endl;
	return 0;
}