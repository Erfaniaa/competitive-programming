/*
	SubmissionId	:	6502096
	ContestId	:	425
	Index	:	D
	ProblemName	:	Sereja and Squares
	ProblemTags	:	['binary search', 'data structures', 'hashing']
	ProgrammingLanguage	:	GNU C++0x
	Verdict	:	OK
*/

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
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

int ans, n, x[MAXN + 10], y[MAXN + 10];
map<int, bool> b[MAXN + 10];
vector<int> col[MAXN + 10], row[MAXN + 10];

int main()
{
	cin >> n;
	FOR (i, 1, n)
	{
		cin >> x[i] >> y[i];
		b[x[i]][y[i]] = 1;
		col[x[i]].pb(y[i]);
		row[y[i]].pb(x[i]);
	}
	FOR (i, 1, n)
	{
		if (SZ(row[y[i]]) <= SZ(col[x[i]]))
		{
			FOR (j, 0, SZ(row[y[i]]) - 1)
			{
				if (row[y[i]][j] > x[i])
				{
					int a = row[y[i]][j] - x[i];
					if ((y[i] - a >= 0) && (x[i] + a < MAXN) && (b[x[i]].count(y[i] - a) == 1) && (b[x[i] + a].count(y[i] - a) == 1))
						ans++;
				}
			}
		}
		else
		{
			FOR (j, 0, SZ(col[x[i]]) - 1)
			{
				if (col[x[i]][j] < y[i])
				{
					int a = y[i] - col[x[i]][j];
					if ((y[i] - a >= 0) && (x[i] + a < MAXN) && (b[x[i] + a].count(y[i]) == 1) && (b[x[i] + a].count(y[i] - a) == 1))
						ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}