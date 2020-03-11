/*
	SubmissionId	:	42058605
	ContestId	:	1029
	Index	:	B
	ProblemName	:	Creating the Contest
	ProblemTags	:	['dp', 'greedy', 'math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[200010];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int j = 0;
	int ans = 1;
	for (int i = 0; i < n; i++) {
		j = i;
		while (j + 1 < n && 2 * a[j] >= a[j + 1])
			j++;
		ans = max(ans, j - i + 1);
		i = j;
	}
	cout << ans << endl;
	return 0;
}