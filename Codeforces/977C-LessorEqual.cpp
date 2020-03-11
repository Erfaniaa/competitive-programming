/*
	SubmissionId	:	37953762
	ContestId	:	977
	Index	:	C
	ProblemName	:	Less or Equal
	ProblemTags	:	['sortings']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int n, k, a[MAXN];
map<int, int> cnt;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	sort(a, a + n);
	if (k == 0 && a[0] == 1)
		cout << -1 << endl;
	else if (k == 0 && a[0] != 1)
		cout << 1 << endl;	
	else if (k == n)
		cout << a[k - 1] << endl;
	else if (a[k - 1] != a[k])
		cout << a[k - 1] << endl;
	else
		cout << -1 << endl;
	return 0;
}