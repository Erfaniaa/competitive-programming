/*
	SubmissionId	:	4394702
	ContestId	:	340
	Index	:	B
	ProblemName	:	Maximal Area Quadrilateral
	ProblemTags	:	['brute force', 'geometry']
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
#include<list>
#include<queue>
#include<fstream>
#include<sstream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define MAXN 400

double area(pii p1, pii p2, pii p3)
{
	return 0.5 * (p1.X * p2.Y + p2.X * p3.Y + p3.X * p1.Y
				- p1.Y * p2.X - p2.Y * p3.X - p3.Y * p1.X);
}

pii p[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	FOR (i, 0, n - 1)
		cin >> p[i].X >> p[i].Y;
	double ans = 0;
	FOR (i, 0, n - 1)
		FOR (j, i + 1, n - 1)
		{
			double up = -1;
			double down = -1;
			FOR (k, 0, n - 1)
				if (k != i && k != j)
				{
					double a = area(p[i], p[j], p[k]);
					if (a > 0)
						up = max(up, a);
					else
						down = max(down, -a);
				}
			if (up >= 0 && down >= 0)
				ans = max(ans, up + down);
		}
	cout.precision(10);
	cout << fixed << ans << endl;
	return 0;
}
