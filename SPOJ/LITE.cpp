#include<iostream>
using namespace std;

#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

bool mark[4 * MAXN];
int seg[4 * MAXN], n, mm;

inline void shift(int v, int vl, int vr)
{
	if (mark[v])
	{
		int mid = (vl + vr) / 2;
		mark[2 * v] = !mark[2 * v];
		mark[2 * v + 1] = !mark[2 * v + 1];
		seg[2 * v] = (mid - vl + 1) - seg[2 * v];
		seg[2 * v + 1] = (vr - mid) - seg[2 * v + 1];
		mark[v] = false;
	}
}

inline void update(int v, int vl, int vr, int l, int r)
{
	if (r < vl || vr < l)
		return;
	if (l <= vl && vr <= r)
	{
		seg[v] = (vr - vl + 1) - seg[v];
		mark[v] = !mark[v];
		return;
	}
	shift(v, vl, vr);
	int mid = (vl + vr) / 2;
	update(2 * v, vl, mid, l, r);
	update(2 * v + 1, mid + 1, vr, l, r);
	seg[v] = seg[2 * v] + seg[2 * v + 1];
}

inline int get(int v, int vl, int vr, int l, int r)
{
	if (r < vl || vr < l)
		return 0;
	if (l <= vl && vr <= r)
		return seg[v];
	shift(v, vl, vr);
	int mid = (vl + vr) / 2;
	return get(2 * v, vl, mid, l, r) + get(2 * v + 1, mid + 1, vr, l, r);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> mm;
	FOR (i, 1, mm)
	{
		int q, l, r;
		cin >> q >> l >> r;
		if (q == 0)
			update(1, 1, n, l, r);
		else
			cout << get(1, 1, n, l, r) << "\n";
	}
	return 0;
}