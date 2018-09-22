/*
	SubmissionId	:	39616645
	ContestId	:	996
	Index	:	D
	ProblemName	:	Suit and Tie
	ProblemTags	:	['brute force', 'greedy', 'math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 220

int n, a[MAXN], ans, num[MAXN], total, b[MAXN];

int main() {
	cin >> n;
	for (int i = 0; i < 2 * n; i++)
		cin >> a[i];
	for (int i = 0; i < 2 * n; i++) {
		if (num[a[i]] == 0) {
			total++;
			num[a[i]] = total * 2;
			b[i] = total * 2;
		}
		else {
			b[i] = num[a[i]] + 1;
		}
	}
	for (int i = 0; i < 2 * n; i++)
		for (int j = i + 1; j < 2 * n; j++)
			if (b[i] > b[j])
				ans++;
	cout << ans << endl;
	return 0;
}