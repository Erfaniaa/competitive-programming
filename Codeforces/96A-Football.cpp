/*
	SubmissionId	:	6511499
	ContestId	:	96
	Index	:	A
	ProblemName	:	Football
	ProblemTags	:	['implementation', 'strings']
	ProgrammingLanguage	:	GNU C++0x
	Verdict	:	OK
*/

#include <bits/stdc++.h>
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
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	s += '#';
	int idx = -1;
	FOR (i, 0, SZ(s) - 2)
		if (s[i] != s[i + 1])
		{
			if (i - idx >= 7)
			{
				cout << "YES";
				return 0;
			}
			idx = i;
		}
	cout << "NO";
	return 0;
}