/*
	SubmissionId	:	42390622
	ContestId	:	1037
	Index	:	B
	ProblemName	:	Reach Median
	ProblemTags	:	['greedy']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int n, mid;
long long a[MAXN], s, ans, median;

int main() {
	cin >> n >> s;
	mid = n / 2;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		// if (i < mid)
			// s1.insert(a[i]);
		if (i == mid)
			median = a[i];
		// if (i > mid)
			// s2.insert(a[i]);
	}
	if (s > median) {
		for (int i = 0; i < n; i++)
			if (i >= mid && a[i] <= s)
				ans += abs(s - a[i]);
	}
	if (s < median) {
		for (int i = 0; i < n; i++)
			if (i <= mid && a[i] >= s)
				ans += abs(s - a[i]);
	}
	cout << ans << endl;
	// while (median < s) {
	// 	int nxt = *s2.begin();
	// 	if (median <= s && s <= nxt) {
	// 		ans += s - median;
	// 		median = s;
	// 		break;
	// 	}
	// 	ans += nxt + 1 - median;
	// 	s2.erase(s2.find(nxt));
	// 	median = nxt;
	// 	s2.insert(median + 1);
	// }
	// while (median > s) {
	// 	int prv = *s1.rbegin();
	// 	if (median >= s && s >= prv) {
	// 		ans += median - s;
	// 		median = s;
	// 		break;
	// 	}
	// 	ans += median - prv + 1;
	// 	s1.erase(s1.find(prv));
	// 	median = prv;
	// 	s1.insert(median - 1);
	// }
	return 0;
}