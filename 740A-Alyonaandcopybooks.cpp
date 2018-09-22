/*
	SubmissionId	:	22431028
	ContestId	:	740
	Index	:	A
	ProblemName	:	Alyona and copybooks
	ProblemTags	:	['brute force', 'implementation']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

long long n, a, b, c, ans = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;

int main()
{
	cin >> n >> a >> b >> c;
	for (long long i = 0; i <= 4; i++)
		for (long long j = 0; j <= 4; j++)
			for (long long k = 0; k <= 4; k++)
				if ((n + i * 1 + j * 2 + k * 3) % 4 == 0)
					ans = min(ans, i * a + j * b + k * c);
	cout << ans << endl;
	return 0;
}