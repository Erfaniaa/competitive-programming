#include <bits/stdc++.h>

using namespace std;

#define MAXN 200000010

int n;
bool prime[MAXN], mark[MAXN];
long long ans;

int main()
{
	cin >> n;
	prime[1] = true;
	for (int i = 2; i * i <= n; i++)
		if (!prime[i])
			for (int j = 2 * i; j <= n; j += i)
				prime[j] = true;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i)
			if (prime[i + j / i])
				mark[j] = true;
	for (int i = 1; i <= n; i++)
		if (!mark[i])
		{
			ans += i;
			if (i <= 1000)
				cout << i << " ";
		}
	cout << ans << endl;
	return 0;
}