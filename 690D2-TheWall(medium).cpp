/*
	SubmissionId	:	19014170
	ContestId	:	690
	Index	:	D2
	ProblemName	:	The Wall (medium)
	ProblemTags	:	['combinatorics']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000003ll

long long power(long long x, long long y)
{
	if (y == 0)
		return 1;
	long long tmp = power(x, y / 2);
	if (y % 2 == 0)
		return (tmp * tmp) % MOD;
	else
		return (tmp * tmp * x) % MOD;
}

long long inv(long long x)
{
	return power(x, MOD - 2);
}

long long fact(long long x)
{
	long long ret = 1;
	for (long long i = 1; i <= x; i++)
		ret = (ret * i) % MOD;
	return ret;
}

long long n, r, ans;

int main()
{
	cin >> n >> r;
	ans = fact(n + r);
	ans = (ans * inv(fact(r))) % MOD;
	ans = (ans * inv(fact(n))) % MOD;
	cout << (ans + MOD - 1) % MOD << endl;
	return 0;
}