/*
	SubmissionId	:	13672400
	ContestId	:	259
	Index	:	D
	ProblemName	:	Little Elephant and Elections
	ProblemTags	:	['brute force', 'combinatorics', 'dp', 'math']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <cstdio>

using namespace std;

#define MOD 1000000007
int n;
long long a[10];

int digitCount(int x)
{
	int ret = 0;
	while (x)
	{
		x /= 10;
		ret++;
	}
	return ret - 1;
}

int power(int x, int b)
{
	int ret = 1;
	for (int i = 1; i <= b; i++)
		ret *= x;
	return ret;
}

int getLastDigit(int x)
{
	while (x >= 10)
		x /= 10;
	return x;
}

int delLastDigit(int x)
{
	int tmp = 1;
	while (x % (tmp * 10) != x)
		tmp *= 10;
	return x % tmp;
}

int calc(int x, int luckies)
{
	if (luckies < 0)
		return 0;
	if (x == 0)
	{
		if (luckies == 0)
			return 1;
		else
			return 0;
	}
	long long ret = 0;
	int d = getLastDigit(x);
	int digitNum = digitCount(x);
	if (digitNum == 0)
	{
		if (luckies > 1)
			return 0;
		int l = 0;
		for (int i = 0; i <= d; i++)
			l += (i == 4 || i == 7);
		if (luckies == 0)
			return d + 1 - l;
		else
			return l;
	}
	int tmp1 = calc(delLastDigit(x), luckies);
	int tmp2 = calc(delLastDigit(x), luckies - 1);
	int tmp3 = calc(power(10, digitNum) - 1, luckies);
	int tmp4 = calc(power(10, digitNum) - 1, luckies - 1);
	for (int i = 0; i < d; i++)
	{
		if (i == 4 || i == 7)
			ret = (ret + tmp4) % MOD;
		else
			ret = (ret + tmp3) % MOD;
	}
	if (d == 4 || d == 7)
		ret = (ret + tmp2) % MOD;
	else
		ret = (ret + tmp1) % MOD;
	return (int)ret;
}

int main()
{
	scanf("%d", &n);
	long long ans = 0;
	for (int i = 0; i <= 9; i++)
		a[i] = calc(n, i);
	a[0]--;
	for (int i = 0; i <= 9; i++)
	for (int c1 = 0; c1 < i; c1++)
	for (int c2 = 0; c2 < i; c2++)
	for (int c3 = 0; c3 < i; c3++)
	for (int c4 = 0; c4 < i; c4++)
	for (int c5 = 0; c5 < i; c5++)
	for (int c6 = 0; c6 < i; c6++)
		if (c1 + c2 + c3 + c4 + c5 + c6 < i)
		{
			long long tmp = a[i];
			tmp = (tmp * (a[c1]--)) % MOD;
			tmp = (tmp * (a[c2]--)) % MOD;
			tmp = (tmp * (a[c3]--)) % MOD;
			tmp = (tmp * (a[c4]--)) % MOD;
			tmp = (tmp * (a[c5]--)) % MOD;
			tmp = (tmp * (a[c6]--)) % MOD;
			ans = (ans + tmp) % MOD;
			a[c1]++;
			a[c2]++;
			a[c3]++;
			a[c4]++;
			a[c5]++;
			a[c6]++;
		}
	printf("%d\n", (int)ans);
	return 0;
}