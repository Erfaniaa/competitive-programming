/*
	SubmissionId	:	38176203
	ContestId	:	978
	Index	:	C
	ProblemName	:	Letters
	ProblemTags	:	['binary search', 'implementation', 'two pointers']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int n, m;
long long a[MAXN], b[MAXN];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0)
			b[i] = a[i];
		else
			b[i] = b[i - 1] + a[i];
	}
	int lastIdx = 0;
	for (int i = 0; i < m; i++) {
		long long x;
		cin >> x;
		x--;
		while (b[lastIdx] <= x)
			lastIdx++;
		long long start = 0;
		if (lastIdx - 1 >= 0)
			start = b[lastIdx - 1];
		cout << lastIdx + 1 << " " << x - start + 1ll << endl;
	}
	return 0;
}