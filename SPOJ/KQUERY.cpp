#include <bits/stdc++.h>

using namespace std;

#define MAXQ 200010
#define MAXN 30010

struct Query
{
	int idx, type, val, l, r;
};

vector<Query> queries;
int fen[MAXN], ans[MAXQ], n, q;

inline bool compare(const Query &q1, const Query &q2)
{
	if (q1.val != q2.val)
		return q1.val < q2.val;
	return q1.type < q2.type;
}

inline int getSum(int idx)
{
	int ret = 0;
	for (; idx; idx -= (idx & -idx))
		ret += fen[idx];
	return ret;
}

inline int update(int idx, int x)
{
	for (; idx <= n; idx += (idx & -idx))
		fen[idx] += x;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		Query query;
		scanf("%d", &query.val);
		query.type = 0;
		query.l = query.r = i;
		queries.push_back(query);
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		Query query;
		scanf("%d%d%d", &query.l, &query.r, &query.val);
		query.idx = i;
		query.type = 1;
		queries.push_back(query);
	}
	sort(queries.begin(), queries.end(), compare);
	for (int i = 0; i < queries.size(); i++)
	{
		if (queries[i].type == 0)
			update(queries[i].l, 1);
		else
			ans[queries[i].idx] = queries[i].r - queries[i].l + 1 - (getSum(queries[i].r) - getSum(queries[i].l - 1));
	}
	for (int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
	return 0;
}