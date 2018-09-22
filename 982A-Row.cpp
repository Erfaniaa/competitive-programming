/*
	SubmissionId	:	38368478
	ContestId	:	982
	Index	:	A
	ProblemName	:	Row
	ProblemTags	:	['brute force', 'constructive algorithms']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
	cin >> n;
	cin >> s;
	bool valid = true;
	for (int i = 0; i < n - 1; i++)
		if (s[i] == '1' && s[i + 1] == '1')
			valid = false;
	for (int i = 0; i < n - 2; i++)
		if (s[i] == '0' && s[i + 1] == '0' && s[i + 2] == '0')
			valid = false;
	if (s == "0" || s == "00")
		valid = false;
	if (n >= 2) {
		if (s[0] == '0' && s[1] == '0')
			valid = false;
		if (s[n - 1] == '0' && s[n - 2] == '0')
			valid = false;
	}
	if (valid)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}