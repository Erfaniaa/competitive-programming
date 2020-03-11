/*
	SubmissionId	:	4194679
	ContestId	:	333
	Index	:	D
	ProblemName	:	Characteristics of Rectangles
	ProblemTags	:	['binary search', 'bitmasks', 'brute force', 'implementation', 'sortings']
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
#define mp make_pair
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 1001

bool mark[MAXN][MAXN];
int a[MAXN][MAXN], xx, yy;

bool isGood(int m)
{
	memset(mark, false, sizeof mark);
	FOR (x, 1, xx)
	{
		vector<int> v;
		v.clear();
		FOR (y, 1, yy)
			if (a[x][y] >= m)
				v.pb(y);
		FOR (i, 0, SZ(v) - 1)
			FOR (j, i + 1, SZ(v) - 1)
			{
				if (mark[v[i]][v[j]])
					return true;
				mark[v[i]][v[j]] = true;
			}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> yy >> xx;
	FOR (y, 1, yy)
		FOR (x, 1, xx)
			cin >> a[x][y];
	int ans, start = 0, end = INF;
	while (start <= end)
	{
		int m = (start + end) / 2;
		if (isGood(m))
		{
			ans = m;
			start = m + 1;
		}
		else
			end = m - 1;
	}
	cout << ans << '\n';
	return 0;
}
