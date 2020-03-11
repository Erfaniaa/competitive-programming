/*
	SubmissionId	:	37962698
	ContestId	:	977
	Index	:	D
	ProblemName	:	Divide by three, multiply by two
	ProblemTags	:	['dfs and similar', 'math', 'sortings']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n;
pair<unsigned long long, pair<int, int> > a[110];

int cntDiv(unsigned long long x, unsigned long long d) {
	int ret = 0;
	while (x > 0 && x % d == 0) {
		x /= d;
		ret++;
	}
	return ret;
}

bool compare(const pair<unsigned long long, pair<int, int> >& a, const pair<unsigned long long, pair<int, int> >& b) {
	return a.second.first - a.second.second < b.second.first - b.second.second;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		unsigned long long x;
		cin >> x;
		a[i] = make_pair(x, make_pair(cntDiv(x, 2), cntDiv(x, 3)));
	}
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++)
		cout << a[i].first << " ";
	return 0;
}