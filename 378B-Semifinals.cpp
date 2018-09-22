/*
	SubmissionId	:	5562313
	ContestId	:	378
	Index	:	B
	ProblemName	:	Semifinals
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
#define MAXN 100010

int n, a[MAXN], b[MAXN];
bool ans1[MAXN], ans2[MAXN];
int j;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
		cin >> a[i] >> b[i];
	j = 0;
	FOR (i, 1, n)
	{
		while (j + 1 <= n && b[j + 1] < a[i])
			j++;
		if (i + j <= n)
			ans1[i] = true;
	}
	j = 0;
	FOR (i, 1, n)
	{
		while (j + 1 <= n && a[j + 1] < b[i])
			j++;
		if (i + j <= n)
			ans2[i] = true;
	}
	FOR (i, 1, n / 2)
		ans1[i] = ans2[i] = true;
	FOR (i, 1, n)
		cout << ans1[i];
	cout << endl;
	FOR (i, 1, n)
		cout << ans2[i];
	cout << endl;
	return 0;
}