/*
	SubmissionId	:	13637189
	ContestId	:	588
	Index	:	A
	ProblemName	:	Duff and Meat
	ProblemTags	:	['greedy']
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

int idx, n, a[MAXN], p[MAXN], ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> p[i];
		if (p[i] < p[idx])
			idx = i;
		ans += a[i] * p[idx];
	}
	cout << ans << endl;
	return 0;
}