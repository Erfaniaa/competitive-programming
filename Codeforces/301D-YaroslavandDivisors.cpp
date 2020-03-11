/*
	SubmissionId	:	5352564
	ContestId	:	301
	Index	:	D
	ProblemName	:	Yaroslav and Divisors
	ProblemTags	:	['data structures']
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
#define MAXN 200010

struct Tri
{
	int l, r, idx;
	Tri(int _l = 0, int _r = 0, int _idx = 0)
	{
		l = _l;
		r = _r;
		idx = _idx;
	}
	bool operator < (Tri t) const
	{
		return l < t.l;
	}
} q[MAXN];

int tree[MAXN], n, m, ans[MAXN], pos[MAXN], a[MAXN];
vector<int> v[MAXN];

int get(int idx)
{
	int tmp = 0;
	for (; idx > 0; idx -= (idx & -idx))
		tmp += tree[idx];
	return tmp;
}

int update(int idx, int x)
{
	for (; idx <= n; idx += (idx & -idx))
		tree[idx] += x;
}

int getSum(int l, int r)
{
	return get(r) - get(l - 1);
}

int main()
{
	scanf("%d %d", &n, &m);
	FOR (i, 1, n)
	{
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	FOR (i, 1, m)
	{
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].idx = i;
	}
	sort(q + 1, q + m + 1);
	FOR (i, 1, n)
	{
		FOR (j, 1, n / i)
			if (pos[i * j] > pos[i])
			{
				update(pos[i * j], 1);
				v[pos[i]].pb(pos[i * j]);
			}
			else
			{
				update(pos[i], 1);
				v[pos[i * j]].pb(pos[i]);
			}
	}
	q[0] = Tri(1, 1, 0);
	FOR (i, 1, m)
	{
		FORD (j, q[i].l - 1, q[i - 1].l)
			FOR (k, 0, SZ(v[j]) - 1)
				update(v[j][k], -1);
		ans[q[i].idx] = getSum(q[i].l, q[i].r);
	}
	FOR (i, 1, m)
		printf("%d\n", ans[i]);
	return 0;
}