/*
	SubmissionId	:	15251585
	ContestId	:	615
	Index	:	D
	ProblemName	:	Multipliers
	ProblemTags	:	['math', 'number theory']
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
#define MAXN 200010
#define MOD 1000000007

long long cnt[MAXN], ans = 1, num = 1;
int m;

int power(long long a, long long b)
{
	if (b == 0)
		return 1;
	long long tmp = power(a, b / 2);
	if (b % 2 == 0)
		return (tmp * tmp) % MOD;
	else
		return (((tmp * tmp) % MOD) * a) % MOD;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		cnt[x]++;
		ans = (ans * x) % MOD;
	}
	bool flag = false;
	for (int i = 1; i < MAXN; i++)
		if (cnt[i] & 1)
		{
			cnt[i] /= 2;
			flag = true;
			break;
		}
	if (!flag)
	{
		ans = 1;
		for (int i = 1; i < MAXN; i++)
			if (cnt[i])
				ans = (ans * power(i, cnt[i] / 2)) % MOD;
	}
	for (int i = 1; i < MAXN; i++)
		if (cnt[i])
			ans = power(ans, cnt[i] + 1);
	cout << ans << endl;
	return 0;
}