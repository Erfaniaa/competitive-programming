/*
	SubmissionId	:	5109836
	ContestId	:	362
	Index	:	B
	ProblemName	:	Petya and Staircases
	ProblemTags	:	['implementation', 'sortings']
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

int a[MAXN], n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	bool ans = true;
	FOR (i, 0, m - 1)
	{
		cin >> a[i];
		if (a[i] == 1 || a[i] == n)
			ans = false;
	}
	sort(a, a + m);
	FOR (i, 1, m - 2)
		if (a[i] == a[i - 1] + 1 && a[i] == a[i + 1] - 1)
			ans = false;
	if (ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}