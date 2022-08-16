#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define VAL (3.0/7)

long long bs(long long d)
{
	long long l = 0;
	long long r = d;
	long long ret = l;
	while (l < r)
	{
		long long mid = (l + r) / 2;
		if ((long double)mid < (long double)VAL * d)
		{
			l = mid + 1;
			ret = mid;
		}
		else
			r = mid - 1;
	}
	return ret;
}

long long ans, n;
long double mn = 1000000;

int main()
{
	cin >> n;
	for (long long i = 1; i <= n; i++)
	{
		long long x = bs(i);
		if (VAL - (long double)x / i < mn)
		{
			mn = VAL - (long double)x / i;
			ans = x / __gcd(i, x);
			//if (i == 1000000)
				cout << x << "/" << i << endl;
		}
	}
	cout << ans << endl;
	return 0;
}