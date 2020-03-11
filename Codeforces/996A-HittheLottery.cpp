/*
	SubmissionId	:	39609520
	ContestId	:	996
	Index	:	A
	ProblemName	:	Hit the Lottery
	ProblemTags	:	['dp', 'greedy']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int ans, n;

int main() {
	cin >> n;
	ans += n / 100;
	n %= 100;
	ans += n / 20;
	n %= 20;
	ans += n / 10;
	n %= 10;
	ans += n / 5;
	n %= 5;
	ans += n / 1;
	n %= 1;
	cout << ans << endl;
	return 0;
}