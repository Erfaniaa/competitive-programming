#include <iostream>

using namespace std;

int n;
long long dp[5][100];

int main()
{
	cin >> n;
	for (int i = 0; i < 5; i++)
		dp[i][0] = 1;
	for (int j = 2; j <= 4; j++)
		for (int i = 1; i <= n; i++)
		{
			dp[j][i] = dp[j][i - 1];
			if (i >= j)
				dp[j][i] += dp[j][i - j];
		}
	cout << dp[2][n] + dp[3][n] + dp[4][n] - 3 << endl;
	return 0;
}