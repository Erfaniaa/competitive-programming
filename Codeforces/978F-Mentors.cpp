/*
	SubmissionId	:	38173584
	ContestId	:	978
	Index	:	F
	ProblemName	:	Mentors
	ProblemTags	:	['binary search', 'data structures', 'implementation']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int a[MAXN], b[MAXN], n, m;
map<int, vector<int> > adj;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		int ans = lower_bound(b, b + n, a[i]) - b;
		int sz = adj[i].size();
		for (int j = 0; j < sz; j++)
			if (a[adj[i][j]] < a[i])
				ans--;
		cout << ans << " ";
	}
	return 0;
}