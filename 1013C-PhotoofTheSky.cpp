/*
	SubmissionId	:	40955849
	ContestId	:	1013
	Index	:	C
	ProblemName	:	Photo of The Sky
	ProblemTags	:	['implementation', 'math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define INF (1000000000ll * 1000000000ll)

long long a[MAXN * 2];
int n;

int main() {
	cin >> n;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < 2 * n; i++)
		cin >> a[i];
	sort(a, a + 2 * n);
	long long ans1 = a[2 * n - 1] - a[0];
	long long mn = INF;
	for (int i = 1; i + n - 1 < 2 * n - 1; i++)
		mn = min(mn, a[i + n - 1] - a[i]);
	ans1 *= mn;
	long long ans2 = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
	cout << min(ans1, ans2) << endl;
	return 0;
}