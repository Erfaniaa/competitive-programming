/*
	SubmissionId	:	42923391
	ContestId	:	1041
	Index	:	B
	ProblemName	:	Buying a TV Set
	ProblemTags	:	['math']
	ProgrammingLanguage	:	GNU C++17
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

long long gcd(long long x, long long y) {
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

long long a, b, x, y;

int main() {
	cin >> a >> b >> x >> y;
	long long g = gcd(x, y);
	x /= g;
	y /= g;
	long long ans1 = a / x;
	long long ans2 = b / y;
	cout << min(ans1, ans2) << endl;
	return 0;
}