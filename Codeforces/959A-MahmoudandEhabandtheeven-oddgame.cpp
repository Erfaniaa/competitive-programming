/*
	SubmissionId	:	36909388
	ContestId	:	959
	Index	:	A
	ProblemName	:	Mahmoud and Ehab and the even-odd game
	ProblemTags	:	['games', 'math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n & 1)
		cout << "Ehab" << endl;
	else
		cout << "Mahmoud" << endl;
	return 0;
}