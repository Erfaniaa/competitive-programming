/*
	SubmissionId	:	40945089
	ContestId	:	1013
	Index	:	B
	ProblemName	:	And
	ProblemTags	:	['greedy']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int n, a[MAXN], x;
int cnt[MAXN], cnt2[MAXN];
bool ans = false;

int main() {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		if (cnt[a[i]] >= 2) {
			cout << 0 << endl;
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		int tmp1 = a[i];
		int tmp2 = a[i] & x;
		cnt[tmp1]--;
		if (cnt[tmp2] >= 1) {
			cout << 1 << endl;
			return 0;
		}
		cnt2[tmp2]++;
		if (cnt2[tmp2] >= 2) {
			ans = true;
		}
		cnt[tmp1]++;
	}
	if (ans)
		cout << 2 << endl;
	else
		cout << -1 << endl;
	return 0;
}