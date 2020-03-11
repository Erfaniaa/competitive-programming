/*
	SubmissionId	:	18306358
	ContestId	:	680
	Index	:	B
	ProblemName	:	Bear and Finding Criminals
	ProblemTags	:	['constructive algorithms', 'implementation']
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

bool isValid(int p, int n)
{
	return (p >= 1) && (p <= n);
}

int n, a, x[1010], ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> a;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0, tmp = 0;
		if (isValid(a - i, n))
		{
			cnt++;
			tmp += x[a - i];
		}
		if (isValid(a + i, n))
		{
			cnt++;
			tmp += x[a + i];
		}
		if (cnt > 0 && tmp == cnt)
			ans += tmp;
	}
	ans += x[a];
	cout << ans << endl;
	return 0;
}