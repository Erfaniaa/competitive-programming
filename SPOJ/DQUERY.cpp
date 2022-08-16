#include <bits/stdc++.h>

using namespace std;

#define MAXN 30010
#define MAXQ 200010

struct Three
{
	int l, r, idx;
	inline Three(int _l = 0, int _r = 0, int _idx = 0)
	{
		l = _l;
		r = _r;
		idx = _idx;
	}
	inline bool operator < (const Three& t)
	{
		if (r != t.r)
			return r < t.r;
		if (l != t.l)
			return l < t.l;
		if (idx != t.idx)
			return idx < t.idx;
	}
} query[MAXQ];

int n, q, fen[MAXN], last[1000010], a[MAXN], ans[MAXQ];

inline void inc(int idx, int val)
{
	for (; idx <= n; idx += (idx & -idx))
		fen[idx] += val;
}

inline int getSum(int idx)
{
	int ret = 0;
	for (; idx >= 1; idx -= (idx & -idx))
		ret += fen[idx];
	return ret;
}

inline int getSum(int l, int r)
{
	return getSum(r) - getSum(l - 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d", &query[i].l, &query[i].r);
		query[i].idx = i;
	}
	sort(query + 1, query + q + 1);
	int idx = 0;
	for (int i = 1; i <= q; i++)
	{
		while (idx < query[i].r)
		{
			idx++;
			if (last[a[idx]])
				inc(last[a[idx]], -1);
			inc(idx, +1);
			last[a[idx]] = idx;
		}
		ans[query[i].idx] = getSum(query[i].l, query[i].r);
	}
	for (int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
	return 0;
}