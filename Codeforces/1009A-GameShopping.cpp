/*
	SubmissionId	:	40323681
	ContestId	:	1009
	Index	:	A
	ProblemName	:	Game Shopping
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

int n, m, a[MAXN], c[MAXN], ans;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> c[i];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (j < m && c[j] >= a[i]) {
			j++;
			ans++;
		}
	cout << ans << endl;
	return 0;
}