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

long long dp[100], ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	for (int i = 3; i <= 30; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	ans = dp[30];
	for (int i = 0; i <= 29; i++)
		ans += dp[i] * dp[29 - i];
	cout << ans << endl;
	return 0;
}