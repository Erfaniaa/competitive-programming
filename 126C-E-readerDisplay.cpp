/*
	SubmissionId	:	5180407
	ContestId	:	126
	Index	:	C
	ProblemName	:	E-reader Display
	ProblemTags	:	['constructive algorithms', 'greedy']
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
#define MAXN 2010

int a[MAXN][MAXN], row[MAXN], col[MAXN], ans, n;
char ch;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (y, 1, n)
		FOR (x, 1, n)
		{
			cin >> ch;
			a[x][y] = (ch == '1');
		}
	FORD (x, n, 1)
		FOR (y, 1, x - 1)
			if ((a[x][y] + row[y] + col[x]) % 2 == 1)
			{
				ans++;
				row[y] = 1 - row[y];
				col[x] = 1 - col[x];
				a[x][x] = 1 - a[x][x];
				a[y][y] = 1 - a[y][y];
			}
	memset(col, 0, sizeof col);
	memset(row, 0, sizeof row);
	FOR (x, 1, n)
		FORD (y, n, x + 1)
			if ((a[x][y] + row[y] + col[x]) % 2 == 1)
			{
				ans++;
				row[y] = 1 - row[y];
				col[x] = 1 - col[x];
				a[x][x] = 1 - a[x][x];
				a[y][y] = 1 - a[y][y];
			}
	FOR (i, 1, n)
		if (a[i][i] % 2 == 1)
			ans++;
	cout << ans << endl;
	return 0;
}