/*
	SubmissionId	:	14759014
	ContestId	:	598
	Index	:	A
	ProblemName	:	Tricky Sum
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
#define MAXN 100010

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		long long n, tmp = 1;
		cin >> n;
		long long ans = n * (n + 1) / 2;
		while (tmp <= n)
		{
			ans -= 2 * tmp;
			tmp *= 2;
		}
		cout << ans << endl;
	}
	return 0;
}