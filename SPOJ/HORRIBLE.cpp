#include<iostream>
#include<memory.h>
using namespace std;

typedef long long ll;
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define MAXN 100010

ll seg[4 * MAXN], mark[4 * MAXN];

inline void shift(int v, int vl, int vr)
{
	if (mark[v] != 0)
	{
		int mid = (vl + vr) / 2;
		mark[2 * v] += mark[v];
		mark[2 * v + 1] += mark[v];
		seg[2 * v] += (mid - vl + 1) * mark[v];
		seg[2 * v + 1] += (vr - mid) * mark[v];
		mark[v] = 0;
	}
}

inline void update(int v, int vl, int vr, int l, int r, ll val)
{
	if (r < vl || vr < l)
		return;
	if (l <= vl && vr <= r)
	{
		seg[v] += (vr - vl + 1) * val;
		mark[v] += val;
		return;
	}
	shift(v, vl, vr);
	int mid = (vl + vr) / 2;
	update(2 * v, vl, mid, l, r, val);
	update(2 * v + 1, mid + 1, vr, l, r, val);
	seg[v] = seg[2 * v] + seg[2 * v + 1];
}

inline ll getSum(int v, int vl, int vr, int l, int r)
{
	if (r < vl || vr < l)
		return 0;
	if (l <= vl && vr <= r)
		return seg[v];
	shift(v, vl, vr);
	int mid = (vl + vr) / 2;
	return getSum(2 * v, vl, mid, l, r) + getSum(2 * v + 1, mid + 1, vr, l, r);
}

int t, n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	FOR (tt, 1, t)
	{
		if (tt != 1)
		{
			memset(seg, 0, sizeof seg);
			memset(mark, 0, sizeof mark);
		}
		cin >> n >> m;
		FOR (k, 1, m)
		{
			int q, l, r;
			ll val;
			cin >> q >> l >> r;
			if (!q)
			{
				cin >> val;
				update(1, 1, n, l, r, val);
			}
			else
				cout << getSum(1, 1, n, l, r) << '\n';
		}
	}
	return 0;
}