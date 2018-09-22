/*
	SubmissionId	:	5878889
	ContestId	:	388
	Index	:	A
	ProblemName	:	Fox and Box Accumulation
	ProblemTags	:	['greedy', 'sortings']
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
#define MAXN 110

int n, a[MAXN];
vector<int> pile[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 0, n - 1)
		cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	FOR (k, 1, n)
	{
		FOR (i, 0, k)
			pile[i].clear();
		bool flag = true;
		FOR (i, 0, n - 1)
		{
			int p = i % k;
			FOR (j, 0, SZ(pile[p]) - 1)
				if (pile[p][j] - (SZ(pile[p]) - j - 1) <= 0)
					flag = false;
			if (!flag)
				break;
			pile[p].pb(a[i]);
		}
		if (flag)
		{
			cout << k;
			return 0;
		}
	}
	return 0;
}