/*
	SubmissionId	:	18307656
	ContestId	:	680
	Index	:	A
	ProblemName	:	Bear and Five Cards
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

long long sum, a[10], ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	ans = sum;
	sort(a, a + 5);
	reverse(a, a + 5);
	for (int i = 0; i <= 2; i++)
		if (a[i] == a[i + 1] && a[i + 1] == a[i + 2])
			ans = min(ans, sum - a[i] - a[i + 1] - a[i + 2]);
	for (int i = 0; i <= 3; i++)
		if (a[i] == a[i + 1])
			ans = min(ans, sum - a[i] - a[i + 1]);
	cout << ans << endl;
	return 0;
}