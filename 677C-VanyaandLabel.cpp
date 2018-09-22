/*
	SubmissionId	:	18193650
	ContestId	:	677
	Index	:	C
	ProblemName	:	Vanya and Label
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

string s;
long long ans;
int cnt[256];

char intToChar(int x)
{
	if (x >= 0 && x <= 9)
		return (x - 0) + '0';
	if (x >= 10 && x <= 35)
		return (x - 10) + 'A';
	if (x >= 36 && x <= 61)
		return (x - 36) + 'a';
	if (x == 62)
		return '-';
	if (x == 63)
		return '_';
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 64; i++)
		for (int j = 0; j < 64; j++)
			cnt[intToChar(i & j)]++;
	cin >> s;
	ans = 1;
	for (int i = 0; i < s.length(); i++)
		ans = (ans * cnt[s[i]]) % MOD;
	cout << ans << endl;
	return 0;
}