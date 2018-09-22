/*
	SubmissionId	:	38363654
	ContestId	:	982
	Index	:	B
	ProblemName	:	Bus of Characters
	ProblemTags	:	['data structures', 'greedy', 'implementation']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int n, w[MAXN];
string s;
set<pair<int, int> > empties;
set<pair<int, int>, greater<pair<int, int> > > fulls;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		empties.insert(make_pair(w[i], i + 1));
	}
	cin >> s;
	for (int i = 0; i < 2 * n; i++) {
		if (s[i] == '0') {
			pair<int, int> x = *(empties.begin());
			empties.erase(x);
			fulls.insert(x);
			cout << x.second << " ";
		}
		if (s[i] == '1') {
			pair<int, int> x = *(fulls.begin());
			fulls.erase(x);	
			cout << x.second << " ";
		}
	}
	return 0;
}