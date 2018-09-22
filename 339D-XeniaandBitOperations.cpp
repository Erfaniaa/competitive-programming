/*
	SubmissionId	:	4353081
	ContestId	:	339
	Index	:	D
	ProblemName	:	Xenia and Bit Operations
	ProblemTags	:	['data structures', 'trees']
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
#define MAXN 200010

int v[20][MAXN], n, m, a[MAXN];

int calc(int depth, int num)
{
	if (depth == 0)
		return a[num];
	if (v[depth][num] != -1)
		return v[depth][num];
	int x = calc(depth - 1, 2 * num);
	int y = calc(depth - 1, 2 * num + 1);
	int ret;
	if (depth % 2 == 0)
		ret = x ^ y;
	else
		ret = x | y;
	return v[depth][num] = ret;
}

int update(int depth, int num, int l, int r, int node)
{
	if (depth == 0)
		return a[num];
	int x = calc(depth - 1, 2 * num);
	int y = calc(depth - 1, 2 * num + 1);
	int m = (l + r) / 2;
	if (node <= m)
		x = update(depth - 1, 2 * num, l, m, node);
	else
		y = update(depth - 1, 2 * num + 1, m + 1, r, node);
	int ret;
	if (depth % 2 == 0)
		ret = x ^ y;
	else
		ret = x | y;
	return v[depth][num] = ret;
}


int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	FOR (i, 0, (1 << n) - 1)
		cin >> a[i];
	memset(v, -1, sizeof v);
	FOR (i, 1, m)
	{
		int p, b;
		cin >> p >> b;
		p--;
		a[p] = b;
		int ans = update(n, 0, 0, (1 << n) - 1, p);
		cout << ans << endl;
	}
	return 0;
}
