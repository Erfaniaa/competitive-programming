/*
	SubmissionId	:	5503635
	ContestId	:	376
	Index	:	A
	ProblemName	:	Lever
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
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

unsigned long long sum1, sum2, p;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	FOR (i, 0, SZ(s) - 1)
		if (s[i] == '^')
		{
			p = i;
			break;
		}
	FOR (i, 0, SZ(s) - 1)
		if (s[i] >= '1' && s[i] <= '9')
		{
			if (i < p)
				sum1 += (unsigned long long)(p - i) * (unsigned long long)(s[i] - '0');
			if (i > p)
				sum2 += (unsigned long long)(i - p) * (unsigned long long)(s[i] - '0');
		}
	if (sum1 > sum2)
		cout << "left\n";
	else if (sum1 < sum2)
		cout << "right\n";
	else
		cout << "balance\n";
	return 0;
}