#include <bits/stdc++.h>

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

int n, q;
int a[MAXN], tree[2 * MAXN];

void update(int v, int vl, int vr, int l, int r, int val)
{
	int inter = min(vr, r) - max(vl, l) + 1;
	if (inter <= 0)
		return;
	if (vl == vr)
		tree[v] += val;
	else
	{
		tree[v] += inter * val;
		int m = (vl + vr) / 2;
		update(2 * v, vl, m, l, r, val);
		update(2 * v + 1, m + 1, vr, l, r, val);
	}
}

int getSum(int v, int vl, int vr, int l, int r)
{
	int inter = min(r, vr) - max(l, vl) + 1;
	if (inter <= 0)
		return 0;
	if (inter == vr - vl + 1)
		return tree[v];
	int m = (vl + vr) / 2;
	return getSum(2 * v, vl, m, l, r)
		 + getSum(2 * v + 1, m + 1, vr, l, r);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
	{
		cin >> a[i];
		update(1, 1, n, i, i, a[i]);
	}
	int x, y, k;
	cin >> x >> y >> k;
	update(1, 1, n, x, y, k);
	cin >> q;
	FOR (i, 1, q)
	{
		int x, y;
		cin >> x >> y;
		cout << getSum(1, 1, n, x, y) << endl;
	}
	return 0;
}