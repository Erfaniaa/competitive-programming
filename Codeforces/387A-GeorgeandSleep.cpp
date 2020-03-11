/*
	SubmissionId	:	5846796
	ContestId	:	387
	Index	:	A
	ProblemName	:	George and Sleep
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

int a, b, c, ans1, ans2, m, h;
char h1, h2, m1, m2, t;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> h1 >> h2 >> t >> m1 >> m2;
	h = (h1 - 48) * 10 + h2;
	m = (m1 - 48) * 10 + m2;
	a = h * 60 + m;
	cin >> h1 >> h2 >> t >> m1 >> m2;
	h = (h1 - 48) * 10 + h2;
	m = (m1 - 48) * 10 + m2;
	b = h * 60 + m;
	c = (a - b + (24 * 60)) % (24 * 60);
	ans1 = c / 60;
	ans2 = c % 60;
	if (ans1 < 10)
		cout << 0;
	cout << ans1 << ":";
	if (ans2 < 10)
		cout << 0;
	cout << ans2;
	return 0;
}