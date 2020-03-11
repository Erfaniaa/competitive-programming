/*
	SubmissionId	:	39829802
	ContestId	:	998
	Index	:	A
	ProblemName	:	Balloons
	ProblemTags	:	['constructive algorithms', 'implementation']
	ProgrammingLanguage	:	GNU C++17
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 21

int n;
pair<int, int> a[MAXN];

int main() {
	cin >> n;
	if (n == 1) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a, a + n);
	int sum = 0;
	for (int i = 1; i < n; i++)
		sum += a[i].first;
	if (sum == a[0].first) {
		cout << -1 << endl;
		return 0;
	}
	cout << n - 1 << endl;
	for (int i = 1; i < n; i++)
		cout << a[i].second << " ";
	return 0;
}