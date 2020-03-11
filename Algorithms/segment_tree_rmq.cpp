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

int init(int v, int b, int e)
{
	if (b == e)
	{
		tree[v] = b;
		return a[b];
	}
	else
	{
		int l = init(2 * v, b, (b + e) / 2);
		int r = init(2 * v + 1, (b + e) / 2 + 1, e);
		if (l < r)
		{
			tree[v] = tree[2 * v];
			return l;
		}
		else
		{
			tree[v] = tree[2 * v + 1];
			return r;
		}
	}
}

int findMin(int v, int b, int e, int i, int j)
{
	if (e < i || b > j || b > e)
		return INF;
	if (i <= b && e <= j)
		return a[tree[v]];
	int l = findMin(2 * v, b, (b + e) / 2, i, j);
	int r = findMin(2 * v + 1, (b + e) / 2 + 1, e, i, j);
	return min(l, r);
}

/*
10
1 2 3 4 5 6 7 8 9 10
*/

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
		cin >> a[i];
	cin >> q;
	init(1, 1, n);
	FOR (i, 1, q)
	{
		int x, y;
		cin >> x >> y;
		cout << findMin(1, 1, n, x, y) << endl;
	}
	return 0;
}