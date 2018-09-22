/*
	SubmissionId	:	42368652
	ContestId	:	1037
	Index	:	A
	ProblemName	:	Packets
	ProblemTags	:	['constructive algorithms', 'greedy', 'math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, ans, x = 1;

int main() {
	cin >> n;
	while (x * 2 <= n) {
		x *= 2;
		ans++;
	}
	cout << ans + 1 << endl;
	return 0;
}