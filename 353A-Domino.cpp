/*
	SubmissionId	:	4726248
	ContestId	:	353
	Index	:	A
	ProblemName	:	Domino
	ProblemTags	:	['implementation', 'math']
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
#define mp make_pair
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 10000

int sum1, sum2, x, y, n;
bool flag;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
	{
		cin >> x >> y;
		if (x % 2 != y % 2)
			flag = true;
		sum1 += x;
		sum2 += y;
	}
	if (sum1 % 2 == 0 && sum2 % 2 == 0)
		cout << 0 << endl;
	else if (sum1 % 2 == 1 && sum2 % 2 == 1 && flag)
		cout << 1 << endl;
	else
		cout << -1 << endl;
	return 0;
}