#include <bits/stdc++.h>

using namespace std;

int main()
{
	mark[1] = true;
	for (int i = 2; i * i <= n; i++)
		if (!mark[i])
			for (int j = 2 * i; j <= n; j++)
				mark[j] = true;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		f[i] = (f[i - 1] * n) % 
	return 0;
}