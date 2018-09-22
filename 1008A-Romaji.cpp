/*
	SubmissionId	:	40273509
	ContestId	:	1008
	Index	:	A
	ProblemName	:	Romaji
	ProblemTags	:	['implementation', 'strings']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

bool isVowel(char ch) {
	return (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'u' || ch == 'i');
}

int main() {
	string s;
	bool ans = true;
	cin >> s;
	for (int i = 0; i < (int)s.size() - 1; i++) {
		if (!isVowel(s[i]) && s[i] != 'n' && !isVowel(s[i + 1]))
			ans = false;
	}
	if (!isVowel(s[(int)s.size() - 1]) && s[(int)s.size() - 1] != 'n')
		ans = false;
	if (ans) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}