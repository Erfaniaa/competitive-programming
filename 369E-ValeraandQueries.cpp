/*
	SubmissionId	:	5353830
	ContestId	:	369
	Index	:	E
	ProblemName	:	Valera and Queries
	ProblemTags	:	['binary search', 'data structures']
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
#define MAXN 300010
#define MAXX 1000010

struct Point
{
	int l, r, type, idx;
	Point(int _l = 0, int _r = 0, int _type = 0, int _idx = 0)
	{
		l = _l;
		r = _r;
		type = _type;
		idx = _idx;
	}
	bool operator < (Point q) const
	{
		if (l != q.l)
			return l < q.l;
		if (type != q.type)
			return type < q.type;
		return idx < q.idx;
	}
};

int n, m, tree[MAXX], ans[MAXN];
vector<Point> points;

void update(int idx, int x)
{
	for (; idx <= MAXX; idx += (idx & -idx))
		tree[idx] += x;
}

int get(int idx)
{
	int ret = 0;
	for (; idx > 0; idx -= (idx & -idx))
		ret += tree[idx];
	return ret;
}

int getSum(int l, int r)
{
	if (l - 1 <= r)
		return get(r) - get(l - 1);
	else
		return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	FOR (i, 1, n)
	{
		int l, r;
		cin >> l >> r;
		update(r, 1);
		points.pb(Point(l, r, 0, i));
	}
	FOR (i, 1, m)
	{
		int cnt, x, lx = 0;
		cin >> cnt;
		FOR (j, 1, cnt)
		{
			cin >> x;
			points.pb(Point(lx, x, 1, i));
			lx = x;
		}
		points.pb(Point(x, MAXX, 1, i));
		ans[i] = n;
	}
	sort(ALL(points));
	FOR (i, 0, SZ(points) - 1)
	{
		Point p = points[i];
		//cerr << p.l << " " << p.r << " " << p.type << " " << p.idx << endl;
		if (p.type == 0)
			update(p.r, -1);
		else
			ans[p.idx] -= getSum(p.l, p.r - 1);
	}
	FOR (i, 1, m)
		cout << ans[i] << endl;
	return 0;
}