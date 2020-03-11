/*
	SubmissionId	:	40364537
	ContestId	:	1009
	Index	:	C
	ProblemName	:	Annoying Present
	ProblemTags	:	['greedy', 'math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int m;
long long n, ans;

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		long long x, d;
		cin >> x >> d;
		ans += x * n;
		if (d >= 0)
			ans += d * (n - 1) * n / 2;
		else {
			long long k = (n + 1) / 2;
			ans += d * ((n - k + 1) * (n - k) / 2 + (k - 1) * k / 2);
		}
	}
	cout << fixed << setprecision(10) << (long double)ans / (long double)n << endl;
	return 0;
}