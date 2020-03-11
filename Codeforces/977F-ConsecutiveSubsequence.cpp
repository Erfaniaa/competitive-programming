/*
	SubmissionId	:	37971584
	ContestId	:	977
	Index	:	F
	ProblemName	:	Consecutive Subsequence
	ProblemTags	:	['dp']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int n, a[MAXN], nxt[MAXN], dp[MAXN];
map<int, vector<int> > f;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		f[a[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		int x = a[i];
		int y = i;
		if (f.count(x + 1) == 0)
			continue;
		int idx = lower_bound(f[x + 1].begin(), f[x + 1].end(), y) - f[x + 1].begin();
		if (idx >= f[x + 1].size())
			continue;
		nxt[i] = f[x + 1][idx];
	}
	int ans = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (nxt[i] == 0)
			dp[i] = 1;
		else
			dp[i] = dp[nxt[i]] + 1;
		if (dp[i] > dp[ans])
			ans = i;
	}
	cout << dp[ans] << endl;
	cout << ans + 1;
	while (nxt[ans] != 0) {
		ans = nxt[ans];
		cout << " " << ans + 1;
	}
	return 0;
}