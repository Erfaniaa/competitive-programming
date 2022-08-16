#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define pb push_back
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

int a[MAXN], n, m;
vector<int> seg[4 * MAXN], idx;

inline void init(int v, int vl, int vr)
{
	if (vl == vr)
		seg[v].pb(a[vl]);
	else
	{
		int mid = (vl + vr) / 2;
		init(2 * v, vl, mid);
		init(2 * v + 1, mid + 1, vr);
		seg[v].resize(vr - vl + 1);
		merge(ALL(seg[2 * v]), ALL(seg[2 * v + 1]), seg[v].begin());
	}
}

inline void get(int v, int vl, int vr, int l, int r)
{
	if (r < vl || vr < l)
		return;
	if (l <= vl && vr <= r)
		idx.pb(v);
	else
	{
		int mid = (vl + vr) / 2;
		get(2 * v, vl, mid, l, r);
		get(2 * v + 1, mid + 1, vr, l, r);
	}
}

inline int cnt(int k)
{
	int ret = 0;
	FOR (i, 0, SZ(idx) - 1)
		ret += lower_bound(ALL(seg[idx[i]]), k) - seg[idx[i]].begin();
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	FOR (i, 1, n)
		cin >> a[i];
	init(1, 1, n);
	sort(a + 1, a + n + 1);
	FOR (i, 1, m)
	{
		idx.clear();
		int x, y, k, t;
		cin >> x >> y >> k;
		k--;
		get(1, 1, n, x, y);
		int l = 1;
		int r = n;
		int ans = -INF - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			int tmp = cnt(a[mid]);
			if (tmp <= k)
			{
				l = mid + 1;
				if (tmp == k && a[mid] > ans)
					ans = a[mid];
			}
			else
				r = mid - 1;
		}
		cout << ans << "\n";
	}
	return 0;
}