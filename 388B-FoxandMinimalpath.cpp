/*
	SubmissionId	:	5889907
	ContestId	:	388
	Index	:	B
	ProblemName	:	Fox and Minimal path
	ProblemTags	:	['bitmasks', 'constructive algorithms', 'graphs', 'implementation', 'math']
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
#define MAXN 1010
#define C 100

bool edge[MAXN][MAXN];
int k;

inline void addEdge(int x, int y)
{
	edge[x][y] = edge[y][x] = 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	int tmp = 1;
	int v = 3;
	int u = v + 2 * C;
	while (tmp * 2 <= k)
	{
		addEdge(v, C + 2 * v + 0);
		addEdge(v, C + 2 * v + 1);
		//
		addEdge(v + 1, C + 2 * v + 0);
		addEdge(v + 1, C + 2 * v + 1);
		//
		addEdge(u + 0, u + 1);
		addEdge(u + 1, u + 2);
		v++;
		u += 2;
		tmp *= 2;
	}
	addEdge(1, 3 + 2 * C);
	addEdge(v, 2);
	FOR (i, 0, 30)
		if (k & (1 << i))
			addEdge(u - (2 * i), v - i);
	cout << 300 << "\n";
	FOR (i, 1, 300)
	{
		FOR (j, 1, 300)
			cout << (edge[i][j] ? "Y" : "N");
		cout << "\n";
	}
	return 0;
}