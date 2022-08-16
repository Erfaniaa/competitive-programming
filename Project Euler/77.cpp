#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100001

bool mark[MAXN + 10];
vector<int> primes;
long long dp[MAXN + 10];

int main()
{
	mark[1] = true;
	for (int i = 2; i <= MAXN; i++)
		if (!mark[i])
			for (int j = 2 * i; j <= MAXN; j += i)
				mark[j] = true;
	for (int i = 1; i <= MAXN; i++)
		if (!mark[i])
		{
			primes.push_back(i);
			if (i < 20)
				cout << i << " ";
		}
	cout << endl;
	dp[0] = 1;
	for (int i = 0; i < primes.size(); i++)
		for (int j = 1; j <= MAXN; j++)
			if (j - primes[i] >= 0)
			{
				dp[j] += dp[j - primes[i]];
				if (dp[j] >= 5000)
				{
					//cout << j << endl;
					//j = -1;
					//i = MAXN + 10;
				}
			}
	cout << dp[29994] << endl;
	for (int i = 0; i <= 20; i++)
		cout << i << ": " << dp[i] << endl;
	for (int i = 1; i <= MAXN; i++)
		if (dp[i] > 5000)
		{
			cout << i << endl;
			return 0;
		}
	return 0;
}