/*
	SubmissionId	:	40940405
	ContestId	:	1013
	Index	:	A
	ProblemName	:	Piles With Stones
	ProblemTags	:	['math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, sum;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sum += x;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sum -= x;
	}
	if (sum >= 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}