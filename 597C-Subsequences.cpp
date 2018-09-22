/*
	SubmissionId	:	14315587
	ContestId	:	597
	Index	:	C
	ProblemName	:	Subsequences
	ProblemTags	:	['data structures', 'dp']
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

long long dp[12][MAXN], f[MAXN];

void add(int idx, ll val)
{
	for (; idx < MAXN; idx += (idx & (-idx)))
		f[idx] += val;
}

long long sum(int idx)
{
	long long ret = 0;
	for (; idx >= 1; idx -= (idx & (-idx)))
		ret += f[idx];
	return ret;
}

int a[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		dp[1][i] = 1;
	k++;
	for (int t = 2; t <= k; t++)
	{
		memset(f, 0, sizeof f);
		for (int i = 1; i <= n; i++)
		{
			dp[t][i] = sum(a[i] - 1);
			add(a[i], dp[t - 1][i]);
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += dp[k][i];
	cout << ans << endl;
	return 0;
}