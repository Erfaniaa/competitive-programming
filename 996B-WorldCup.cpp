/*
	SubmissionId	:	39618917
	ContestId	:	996
	Index	:	B
	ProblemName	:	World Cup
	ProblemTags	:	['binary search', 'math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int n, a[MAXN], ansT = 2 * 1000000000, ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int r = 0; r < n; r++) {
		int k = (a[r] - r + n - 1) / n;
		int t = k * n + r;
		if (t < ansT) {
			ansT = t;
			ans = r + 1;
		}
	}
	cout << ans << endl;
	return 0;
}