/*
	SubmissionId	:	5847593
	ContestId	:	387
	Index	:	B
	ProblemName	:	George and Round
	ProblemTags	:	['brute force', 'greedy', 'two pointers']
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
#define MAXN 3010

int n, m, a[MAXN], b[MAXN], last;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	FOR (i, 1, n)
		cin >> a[i];
	FOR (i, 1, m)
		cin >> b[i];
	int j = 1;
	FOR (i, 1, n)
	{
		while (b[j] < a[i] && j <= m)
			j++;
		if (b[j] >= a[i])
		{
			j++;
			last = max(last, i);
		}
	}
	cout << n - last;
	return 0;
}