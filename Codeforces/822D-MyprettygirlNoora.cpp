/*
	SubmissionId	:	28236281
	ContestId	:	822
	Index	:	D
	ProblemName	:	My pretty girl Noora
	ProblemTags	:	['brute force', 'dp', 'greedy', 'math', 'number theory']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007ll
#define MAXN 5000001ll

long long f[MAXN], ans, t;
int l, r;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t >> l >> r;
	for (long long i = 1; i < MAXN; i++)
		f[i] = i * (i - 1) / 2;
	for (long long i = 1; i <= MAXN / 2; i++)
	{
		long long k = 2;
		for (long long j = 2 * i; j <= i * i && j < MAXN; j += i)
			f[j] = min(f[j], i * k * (k++ - 1) / 2 + f[i]);
	}
	long long p = 1;
	for (int i = l; i <= r; i++)
	{
		f[i] = f[i] % MOD;
		long long tmp = (p * f[i]) % MOD;
		ans = (ans + tmp) % MOD;
		p = (p * t) % MOD;
	}
	cout << ans << endl;
	return 0;
}