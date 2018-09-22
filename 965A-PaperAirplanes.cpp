/*
	SubmissionId	:	37606242
	ContestId	:	965
	Index	:	A
	ProblemName	:	Paper Airplanes
	ProblemTags	:	['math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

long long divCeil(long long x, long long y) {
	return (x + y - 1) / y;
}

int main() {
	long long k, n, s, p;
	cin >> k >> n >> s >> p;
	cout << divCeil(k * divCeil(n, s), p) << endl;
	return 0;
}