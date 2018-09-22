/*
	SubmissionId	:	5305762
	ContestId	:	369
	Index	:	B
	ProblemName	:	Valera and Contest
	ProblemTags	:	['constructive algorithms', 'implementation', 'math']
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

int n, l, r, all, sk, n2, k, sum2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> l >> r >> all >> sk;
	sum2 = all - sk;
	n2 = n - k;
	FOR (i, 1, sk % k)
		cout << (sk / k) + 1 << " ";
	FOR (i, 1, k - (sk % k))
		cout << sk / k << " ";
	if (n2)
	{
		FOR (i, 1, sum2 % n2)
			cout << (sum2 / n2) + 1 << " ";
		FOR (i, 1, n2 - (sum2 % n2))
			cout << sum2 / n2 << " ";
	}
	return 0;
}