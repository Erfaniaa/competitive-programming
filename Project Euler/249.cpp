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
#define MOD ((long long)1000 * 1000 * 1000 * 1000 * 10000)
#define MAXN (5000 * 5000 + 10)

bool mark[MAXN];
int n;
long long dp[MAXN], ans, maxSum;
vector<int> primes;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	mark[1] = true;
	for (int i = 2; i <= n; i++)
		if (!mark[i])
			for (int j = 2 * i; j < MAXN; j += i)
				mark[j] = true;
	for (int i = 1; i < n; i++)
		if (!mark[i])
		{
			primes.push_back(i);
			maxSum += i;
		}
	dp[0] = 1;
	for (int i = 0; i < SZ(primes); i++)
		for (int j = maxSum + 1; j >= primes[i]; j--)
			dp[j] = (dp[j] + dp[j - primes[i]]) % MOD;
	for (int i = 1; i <= maxSum; i++)
		if (!mark[i])
			ans = (ans + dp[i]) % MOD;
	cout << ans << endl;
	return 0;
}