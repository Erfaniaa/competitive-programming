/*
	SubmissionId	:	42921153
	ContestId	:	1041
	Index	:	A
	ProblemName	:	Heist
	ProblemTags	:	['greedy', 'implementation', 'sortings']
	ProgrammingLanguage	:	GNU C++17
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

int n, a[MAXN], ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	cout << a[n - 1] - a[0] + 1 - n << endl;
	return 0;
}