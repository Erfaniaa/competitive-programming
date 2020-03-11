/*
	SubmissionId	:	36928996
	ContestId	:	959
	Index	:	E
	ProblemName	:	Mahmoud and Ehab and the xor-MST
	ProblemTags	:	['bitmasks', 'dp', 'graphs', 'implementation', 'math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

long long f(long long x) {
	if (x == 1)
		return 0;
	if (x & 1) {
		long long ret = 2ll * f(x / 2) + x / 2;
		long long tmp = 1ll;
		x--;
		while (tmp <= x) {
			if ((x ^ tmp) < x)
				return ret + tmp;
			tmp *= 2ll;
		}
	}
	else
		return 2ll * f(x / 2) + x / 2;
}

long long n;

int main() {
	cin >> n;
	cout << f(n) << endl;
	return 0;
}