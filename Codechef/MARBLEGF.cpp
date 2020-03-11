#include<iostream>
using namespace std;

typedef long long ll;
#define debug(x) cerr << #x << " = " << x << endl
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define MAXN 1000010

ll a[MAXN], tree[MAXN];
int n, m;

inline void update(int idx, int val)
{
	for (; idx <= n; idx += idx & (-idx))
		tree[idx] += val;
}

inline ll get(int idx)
{
	ll ret = 0;
	for (; idx >= 1; idx -= idx & (-idx))
		ret += tree[idx];
	return ret;
}

inline ll getSum(int l, int r)
{
	return get(r) - get(l - 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	FOR (i, 1, n)
	{
		cin >> a[i];
		update(i, a[i]);
	}
	FOR (i, 1, m)
	{
		char ch;
		int x, y;
		cin >> ch >> x >> y;
		if (ch == 'S')
		{
			x++;
			y++;
			cout << getSum(x, y) << "\n";
		}
		if (ch == 'G')
		{
			x++;
			a[x] += y;
			update(x, y);
		}
		if (ch == 'T')
		{
			x++;
			if (a[x] - y < 0)
				y = a[x];
			a[x] -= y;
			update(x, -y);
		}
	}
	return 0;
}