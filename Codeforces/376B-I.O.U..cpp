/*
	SubmissionId	:	5510102
	ContestId	:	376
	Index	:	B
	ProblemName	:	I.O.U.
	ProblemTags	:	['implementation']
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
#define MAXN 100010

int n, m, edge[200][200], ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	FOR (i, 1, m)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edge[a][b] = w;
		edge[b][a] = -w;
	}
	FOR (k, 1, n)
		FOR (i, 1, n)	
			if (i != k && edge[i][k] > 0)
				FOR (j, 1, n)
					if (j != i && j != k && edge[k][j] > 0)
					{
						int m = min(edge[i][k], edge[k][j]);
						edge[i][k] -= m;
						edge[k][j] -= m;
						edge[k][i] += m;
						edge[j][k] += m;
						edge[i][j] += m;
						edge[j][i] -= m;
					}
	FOR (i, 1, n)
		FOR (j, 1, n)
			if (edge[i][j] > 0)
				ans += edge[i][j];
	cout << ans << endl;
	return 0;
}