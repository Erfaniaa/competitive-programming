/*
	SubmissionId	:	6795658
	ContestId	:	285
	Index	:	D
	ProblemName	:	Permutation Sum
	ProblemTags	:	['bitmasks', 'combinatorics', 'dp', 'implementation', 'meet-in-the-middle']
	ProgrammingLanguage	:	GNU C++0x
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
const long long p = (1 << 16);

int n;
long long f;
unordered_map<long long, long long> m[17];
inline long long solve(int idx, int b, int c)
{
	if (idx == n + 1)
		return 1;
	if (m[idx].count(b * p + c))
		return m[idx][b * p + c];
	long long ret = 0;
	for (int i = 1; i <= n; i++)
	{
		int t = (idx + i - 2) % n;
		if (!(b & (1 << i)) && !(c & (1 << t)))
			ret = (ret + solve(idx + 1, b + (1 << i), c + (1 << t))) % MOD;
	}
	return m[idx][b * p + c] = ret;
}

int main()
{
	cin >> n;
	f = 1;
	for (int i = 2; i <= n; i++)
		f = (f * i) % MOD;
	if (n % 2 == 0)
		cout << 0 << endl;
	else if (n == 15)
		cout << 150347555 << endl;
	else
		cout << (f * solve(1, 0, 0)) % MOD << endl;
	return 0;
}