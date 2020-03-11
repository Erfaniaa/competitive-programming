/*
	SubmissionId	:	5468318
	ContestId	:	374
	Index	:	B
	ProblemName	:	Inna and Nine
	ProblemTags	:	['combinatorics', 'greedy']
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

unsigned long long ans = 1;
string s;

int main()
{
	cin >> s;
	int x = s[0] - '0';
	unsigned long long cnt = 1;
	FOR (i, 1, SZ(s) - 1)
	{
		int y = s[i] - '0';
		if (x + y == 9)
			cnt++;
		else
		{
			if (cnt % 2 == 1)
				ans = ans * (unsigned long long)((cnt + 1) / 2);
			cnt = 1;
		}
		x = y;
	}
	if (cnt % 2 == 1)
		ans = ans * (unsigned long long)((cnt + 1) / 2);
	cout << ans << "\n";
	return 0;
}