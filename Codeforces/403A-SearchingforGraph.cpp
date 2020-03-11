/*
	SubmissionId	:	6033062
	ContestId	:	403
	Index	:	A
	ProblemName	:	Searching for Graph
	ProblemTags	:	['constructive algorithms', 'graphs']
	ProgrammingLanguage	:	GNU C++
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

int n, p, t, tmp;
bool mat[31][31];

void addEdge(int u, int v)
{
	mat[u][v] = mat[v][u] = 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> p;
		memset(mat, 0, sizeof mat);
		FOR (i, 0, n - 1)
		{
			addEdge(i, (i + 1) % n);
			addEdge(i, (i + 2) % n);
		}
		tmp = 0;
		FOR (i, 0, n - 1)
			FOR (j, i + 1, n - 1)
				if (!mat[i][j] && tmp < p)
				{
					addEdge(i, j);
					tmp++;
				}
		FOR (i, 0, n - 1)
			FOR (j, i + 1, n - 1)
				if (mat[i][j])
					cout << i + 1 << " " << j + 1 << endl;
	}
	return 0;
}