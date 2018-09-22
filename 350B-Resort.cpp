/*
	SubmissionId	:	4626697
	ContestId	:	350
	Index	:	B
	ProblemName	:	Resort
	ProblemTags	:	['graphs']
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
#define mp make_pair
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

bool type[MAXN];
int parent[MAXN], deg[MAXN], n;
vector<int> tmp, ans;

void dfs(int v)
{
	tmp.pb(v);
	int p = parent[v];
	if (deg[p] == 1)
		dfs(p);
	else if (SZ(tmp) > SZ(ans))
		ans = tmp;
	tmp.pop_back();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
		cin >> type[i];
	FOR (i, 1, n)
	{
		cin >> parent[i];
		if (parent[i] > 0)
			deg[parent[i]]++;
	}
	FOR (i, 1, n)
		if (type[i])
			dfs(i);
	reverse(ans.begin(), ans.end());
	cout << SZ(ans) << endl;
	FOR (i, 0, SZ(ans) - 1)
		cout << ans[i] << " ";
	return 0;
}