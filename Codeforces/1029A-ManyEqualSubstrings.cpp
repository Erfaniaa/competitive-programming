/*
	SubmissionId	:	42031511
	ContestId	:	1029
	Index	:	A
	ProblemName	:	Many Equal Substrings
	ProblemTags	:	['implementation', 'strings']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;
string t, s;

bool isValid(int idx) {
	if (idx == s.size()) {
		for (int i = 0; i < t.size(); i++)
			s.push_back(t[i]);
		return true;
	}
	for (int i = 0; i < t.size(); i++) {
		if (i + idx >= s.size())
			s.push_back(t[i]);
		else if (t[i] != s[i + idx]) {
			return false;
		}
	}
	return true;
}


int main() {
	cin >> n >> k;
	cin >> t;
	int cnt = 0;
	for (int i = 0; i <= s.size(); i++) {
		if (cnt == k)
			break;
		if (isValid(i))
			cnt++;
	}
	cout << s << endl;
	return 0;
}