/*
	SubmissionId	:	36808595
	ContestId	:	952
	Index	:	B
	ProblemName	:	A Map of the Cat
	ProblemTags	:	['brute force']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	bool isGrumpy = false;
	for (int i = 0; i < 6; i++) {
		cout << i << endl;
		cout.flush();
		string s;
		getline(cin, s);
		if (s == "terrible" || s == "worse" || s == "go die in a hole" || s == "are you serious?" || s == "no way" || s == "don't even")
			isGrumpy = true;
	}
	if (isGrumpy)
		cout << "grumpy" << endl;
	else
		cout << "normal" << endl;
	cout.flush();
	return 0;
}