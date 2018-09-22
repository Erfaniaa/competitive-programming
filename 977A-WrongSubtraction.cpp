/*
	SubmissionId	:	37944557
	ContestId	:	977
	Index	:	A
	ProblemName	:	Wrong Subtraction
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int x, k;

int main() {
	cin >> x >> k;
	for (int i = 1; i <= k; i++) {
		if (x % 10 == 0)
			x /= 10;
		else
			x--;
	}
	cout << x << endl;
	return 0;
}