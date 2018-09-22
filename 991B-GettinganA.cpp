/*
	SubmissionId	:	39552202
	ContestId	:	991
	Index	:	B
	ProblemName	:	Getting an A
	ProblemTags	:	['greedy', 'sortings']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

int n, a[MAXN], sum;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	// int rangeMax = 5 * n;
	// int rangeMin = 4 * n + 1;

	if ((double)sum / (double)n >= 4.5) {
		cout << 0 << endl;
		return 0;
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if ((double)sum / (double)n >= 4.5)
			break;
		if (a[i] != 5) {
			ans++;
			sum += 5 - a[i];
			if ((double)sum / (double)n >= 4.5)
				break;
		}
	}
	cout << ans << endl;
	return 0;
}