/*
	SubmissionId	:	15997331
	ContestId	:	626
	Index	:	C
	ProblemName	:	Block Towers
	ProblemTags	:	['brute force', 'greedy', 'math', 'number theory']
	ProgrammingLanguage	:	GNU C++11
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
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1;; i++)
	{
		int n2 = n - (i / 2 - i / 6);
		int m2 = m - (i / 3 - i / 6);
		if (n2 < 0)
			n2 = 0;
		if (m2 < 0)
			m2 = 0;
		if (n2 + m2 <= i / 6)
		{
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}