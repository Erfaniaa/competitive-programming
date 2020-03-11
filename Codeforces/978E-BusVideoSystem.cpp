/*
	SubmissionId	:	38171043
	ContestId	:	978
	Index	:	E
	ProblemName	:	Bus Video System
	ProblemTags	:	['math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

const long long INF = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;

int n;
long long w, a[MAXN], sum, mn = 0, mx = 0;

int main() {
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		if (sum < mn)
			mn = sum;
		if (sum > mx)
			mx = sum;
	}
	long long x1 = w - mx;
	long long x2 = w - mn;
	long long l = 0, r = w;
	l = max(l, -mn);
	l = max(l, -mx);
	r = min(r, w - mn);
	r = min(r, w - mx);
	if (r - l + 1 <= 0)
		cout << 0 << endl;
	else {
		cout << r - l + 1 << endl;
	}
	return 0;
}