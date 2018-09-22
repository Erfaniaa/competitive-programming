/*
	SubmissionId	:	39558692
	ContestId	:	991
	Index	:	C
	ProblemName	:	Candies
	ProblemTags	:	['binary search', 'implementation']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

long long n;

bool check(long long k) {
	long long a = 0, b = 0, total = n;
	while (total > 0) {
		a += min(total, k);
		total -= min(total, k);
		if (total <= 0)
			break;
		b += total / 10;
		total -= total / 10;
	}
	return (a >= b);
}

int main() {
	cin >> n;
	long long l = 1;
	long long r = n;
	long long ans = n;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}