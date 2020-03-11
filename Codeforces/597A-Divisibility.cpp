/*
	SubmissionId	:	14202644
	ContestId	:	597
	Index	:	A
	ProblemName	:	Divisibility
	ProblemTags	:	['math']
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
#define MAXN 10000

ll x, y, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> x >> y;
	if (x <= 0 && y >= 0)
		cout << -x / k + y / k + 1 << endl;
	else if (x > 0 && y > 0)
		cout << y / k - (x - 1) / k << endl;
	else if (x < 0 && y < 0)
		cout << -x / k - (-y - 1) / k << endl;
	return 0;
}