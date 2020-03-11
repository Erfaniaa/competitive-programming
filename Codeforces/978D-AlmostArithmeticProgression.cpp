/*
	SubmissionId	:	38166666
	ContestId	:	978
	Index	:	D
	ProblemName	:	Almost Arithmetic Progression
	ProblemTags	:	['brute force', 'implementation', 'math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define MAXN 100010

int n, ans = INF;
long long a[MAXN], b[MAXN];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n <= 2) {
		cout << 0 << endl;
		return 0;
	}
	for (int x0 = -1; x0 <= +1; x0++) {
		for (int x1 = -1; x1 <= +1; x1++) {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (i == 0)
					b[0] = a[0] + x0;
				else if (i == 1)
					b[1] = a[1] + x1;
				else
					b[i] = b[0] + (b[1] - b[0]) * (long long)i;
				if (abs(a[i] - b[i]) > 1ll)
					break;
				if (b[i] != a[i])
					cnt++;
				if (i == n - 1)
					ans = min(cnt, ans);
			}
		}
	}
	if (ans != INF)
		cout << ans << endl;
	else
		cout << -1 << endl;
	return 0;
}