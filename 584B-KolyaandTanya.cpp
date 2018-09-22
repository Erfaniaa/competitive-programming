/*
	SubmissionId	:	13455097
	ContestId	:	584
	Index	:	B
	ProblemName	:	Kolya and Tanya 
	ProblemTags	:	['combinatorics']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <iostream>

using namespace std;

long long ans1 = 1, ans2 = 1, cnt;
#define MOD (long long)1000000007
int n;

int main()
{
	cin >> n;
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			for (int k = 1; k <= 3; k++)
				cnt += (int)(i + j + k == 6);
	for (int i = 1; i <= 3 * n; i++)
		ans1 = (ans1 * 3) % MOD;
	for (int i = 1; i <= n; i++)
		ans2 = (ans2 * cnt) % MOD;
	cout << (ans1 - ans2 + 2 * MOD) % MOD << endl;
	return 0;
}