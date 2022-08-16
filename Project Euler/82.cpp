#include <iostream>

using namespace std;

int n;
long long dp[100][100][3], a[100][100];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	for (int j = 1; j <= n; j++)
		for (int k = 0; k <= 2; k++)
			dp[0][j][k] = dp[n + 1][j][k] = 1000 * 1000 * 1000;
	for (int j = 1; j <= n; j++)
	{
		//>
		for (int i = 1; i <= n; i++)
			dp[i][j][0] = a[i][j] + min(dp[i][j - 1][0], min(dp[i][j - 1][1], dp[i][j - 1][2]));
		//v
		for (int i = 1; i <= n; i++)
			dp[i][j][1] = a[i][j] + min(dp[i - 1][j][0], dp[i - 1][j][1]);
		//^
		for (int i = n; i >= 1;	i--)
			dp[i][j][2] = a[i][j] + min(dp[i + 1][j][0], dp[i + 1][j][2]);
	}
	long long ans = 1000 * 1000 * 1000;
	for (int i = 1; i <= n; i++)
		for (int k = 0; k <= 2; k++)
			ans = min(ans, dp[i][n][k]);
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= n; j++)
	// 		cout << min(dp[i][j][0], min(dp[i][j][1], dp[i][j][2])) << " ";
	// 	cout << endl;
	// }
	cout << ans << endl;
	return 0;
}