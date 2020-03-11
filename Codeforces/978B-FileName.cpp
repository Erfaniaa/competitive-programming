/*
	SubmissionId	:	38161640
	ContestId	:	978
	Index	:	B
	ProblemName	:	File Name
	ProblemTags	:	['greedy', 'strings']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

string s;
int cnt, ans, n;

int main() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'x') {
			cnt++;
			// cout << "cnt: " << cnt << endl;
		}
		else {
			// cout << "cnt: " << cnt << endl;
			if (cnt >= 3)
				ans += cnt - 2;
			cnt = 0;
		}
	}
	if (cnt >= 3)
		ans += cnt - 2;
	cout << ans << endl;
	return 0;
}