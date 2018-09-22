/*
	SubmissionId	:	40279338
	ContestId	:	1008
	Index	:	C
	ProblemName	:	Reorder the Array
	ProblemTags	:	['combinatorics', 'math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int n, a[MAXN], cur, ans, sum;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (i == 0 || a[i] != a[i - 1]) {
			sum += cur;
			cur = 1;
		}
		else
			cur++;
		if (sum > 0) {
			sum--;
			ans++;
		}
	}
	cout << ans << endl;
}