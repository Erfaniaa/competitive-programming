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
#define INF ((ll)1000 * 1000 * 1000)
#define MAXN 100010
 
int t, n, m;
ll sqrSum[4 * MAXN], sum[4 * MAXN], mark[4 * MAXN][2];

inline void shift(int v, int vl, int vr)
{
	if (mark[v][0] != INF || mark[v][1] != INF)
	{
		int mid = (vl + vr) / 2;
		sqrSum[2 * v] = (mid - vl + 1) * SQR(mark[v][0] + mark[v][1]);
		sum[2 * v] = (mid - vl + 1) * (mark[v][0] + mark[v][1]);
		sqrSum[2 * v + 1] = (vr - mid) * SQR(mark[v][0] + mark[v][1]);
		sum[2 * v + 1] = (vr - mid) * (mark[v][0] + mark[v][1]);
		mark[2 * v][0] = mark[2 * v + 1][0] = mark[v][0];
		mark[2 * v][1] = mark[2 * v + 1][1] = mark[v][1];
		mark[v][0] = mark[v][1] = INF;
	}
}

inline void setVal(int v, int vl, int vr, int l, int r, ll val)
{
	if (vr < l || r < vl)
		return;
	if (l <= vl && vr <= r)
	{
		sum[v] = (vr - vl + 1) * val;
		sqrSum[v] = (vr - vl + 1) * SQR(val);
		mark[v][0] = val;
		mark[v][1] = 0;
		return;
	}
	shift(v, vl, vr);
	int mid = (vl + vr) / 2;
	setVal(2 * v, vl, mid, l, r, val);
	setVal(2 * v + 1, mid + 1, vr, l, r, val);
	sum[v] = sum[2 * v] + sum[2 * v + 1];
	sqrSum[v] = sqrSum[2 * v] + sqrSum[2 * v + 1];
}

inline void inc(int v, int vl, int vr, int l, int r, ll val)
{
	if (vr < l || r < vl)
		return;
	if (l <= vl && vr <= r)
	{
		sqrSum[v] += 2 * sum[v] * val + (vr - vl + 1) * SQR(val);
		sum[v] += (vr - vl + 1) * val;
		mark[v][1] += val;
		return;
	}
	shift(v, vl, vr);
	int mid = (vl + vr) / 2;
	inc(2 * v, vl, mid, l, r, val);
	inc(2 * v + 1, mid + 1, vr, l, r, val);
	sum[v] = sum[2 * v] + sum[2 * v + 1];
	sqrSum[v] = sqrSum[2 * v] + sqrSum[2 * v + 1];
}

inline ll getSum(int v, int vl, int vr, int l, int r)
{
	if (vr < l || r < vl)
		return 0;
	if (l <= vl && vr <= r)
		return sqrSum[v];
	shift(v, vl, vr);
	int mid = (vl + vr) / 2;
	return getSum(2 * v, vl, mid, l, r) + getSum(2 * v + 1, mid + 1, vr, l, r);
}

 int main()
 {
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cin >> t;
 	FOR (tt, 1, t)
 	{
 		cout << "Case " << tt << ":" << "\n";
 		cin >> n >> m;
 		memset(sqrSum, 0, sizeof sqrSum);
 		memset(sum, 0, sizeof sum);
 		FOR (i, 1, 4 * n)
 			mark[i][0] = mark[i][1] = INF;
 		FOR (i, 1, n)
 		{
 			ll a;
 			cin >> a;
 			setVal(1, 1, n, i, i, a);
 		}
 		FOR (i, 1, m)
 		{
 			int q, l, r;
 			ll val;
 			cin >> q >> l >> r;
 			if (q != 2)
 				cin >> val;
 			if (q == 0)
 				setVal(1, 1, n, l, r, val);
 			if (q == 1)
 				inc(1, 1, n, l, r, val);
 			if (q == 2)
 				cout << getSum(1, 1, n, l, r) << "\n";
 		}
 	}
 	return 0;
 }