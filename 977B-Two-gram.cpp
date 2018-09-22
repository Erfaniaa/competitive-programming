/*
	SubmissionId	:	37946795
	ContestId	:	977
	Index	:	B
	ProblemName	:	Two-gram
	ProblemTags	:	['implementation', 'strings']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n;
string s, ans = "";
map<string, int> cnt;

int main() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < n - 1; i++) {
		cnt[s.substr(i, 2)]++;
		if (cnt[s.substr(i, 2)] > cnt[ans])
			ans = s.substr(i, 2);
	}
	cout << ans << endl;
	return 0;
}