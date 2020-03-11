/*
	SubmissionId	:	13635657
	ContestId	:	588
	Index	:	B
	ProblemName	:	Duff in Love
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

long long n, ans = 1;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (long long i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			ans *= i;
		while (n % i == 0)
			n /= i;
	}
	if (n != 1)
		ans *= n;
	cout << ans << endl;
	return 0;
}