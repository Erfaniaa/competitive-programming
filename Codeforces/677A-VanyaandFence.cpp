/*
	SubmissionId	:	18188450
	ContestId	:	677
	Index	:	A
	ProblemName	:	Vanya and Fence
	ProblemTags	:	['implementation']
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

int n, ans, h;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> h;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		ans++;
		if (x > h)
			ans++;
	}
	cout << ans << endl;
	return 0;
}