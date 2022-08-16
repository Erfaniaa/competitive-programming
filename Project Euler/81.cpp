#include <iostream>

using namespace std;

int n;
long long dp[100][100], a[100][100];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	dp[1][1] = a[1][1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i > 1 && j > 1)
				dp[i][j] = a[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
			else if (j > 1)
				dp[i][j] = a[i][j] + dp[i][j - 1];
			else if (i > 1)
				dp[i][j] = a[i][j] + dp[i - 1][j];
	cout << dp[n][n] << endl;
	return 0;
}