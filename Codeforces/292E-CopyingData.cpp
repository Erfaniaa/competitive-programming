/*
	SubmissionId	:	5289443
	ContestId	:	292
	Index	:	E
	ProblemName	:	Copying Data
	ProblemTags	:	['data structures']
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
#define MAXN 100020

int type, pos, len, start[MAXN], dest[MAXN], a[MAXN], b[MAXN], q, n, seg[4 * MAXN];
bool mark[4 * MAXN];

inline void setVal(int v, int vl, int &vr, int &val, int &l, int r)
{
	if (l <= vl && vr <= r)
	{
		seg[v] = max(seg[v], val);
		mark[v] = true;
		return;
	}
	if (r < vl || l > vr || vl == vr)
		return;
	if (mark[v])
	{
		mark[v] = false;
		mark[2 * v] = mark[2 * v + 1] = true;
		seg[2 * v] = max(seg[2 * v], seg[v]);
		seg[2 * v + 1] = max(seg[2 * v + 1], seg[v]);
	}
	int mid = (vl + vr) / 2;
	setVal(2 * v, vl, mid, val, l, r);
	setVal(2 * v + 1, mid + 1, vr, val, l, r);
	seg[v] = max(seg[2 * v], seg[2 * v + 1]);
}

inline int getVal(int v, int vl, int &vr, int &p)
{
	int mid = (vl + vr) / 2;
	if (vl == vr)
		return seg[v];
	if (mark[v])
	{
		mark[v] = false;
		mark[2 * v] = mark[2 * v + 1] = true;
		seg[2 * v] = max(seg[2 * v], seg[v]);
		seg[2 * v + 1] = max(seg[2 * v + 1], seg[v]);
	}
	if (p <= mid)
		return getVal(2 * v, vl, mid, p);
	else
		return getVal(2 * v + 1, mid + 1, vr, p);
}

int main()
{
	scanf("%d %d", &n, &q);
	FOR (i, 1, n)
		scanf("%d", &b[i]);
	FOR (i, 1, n)
		scanf("%d", &a[i]);
	FOR (i, 1, q)
	{
		scanf("%d", &type);
		if (type == 2)
		{
			scanf("%d", &pos);
			int idx = getVal(1, 1, n, pos);
			if (idx == 0)
				printf("%d\n", a[pos]);
			else
				printf("%d\n", b[start[idx] + pos - dest[idx]]);
		}
		else
		{
			scanf("%d %d %d", &start[i], &dest[i], &len);
			setVal(1, 1, n, i, dest[i], dest[i] + len - 1);
		}
	}
	return 0;
}