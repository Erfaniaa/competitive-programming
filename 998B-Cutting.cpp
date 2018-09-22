/*
	SubmissionId	:	39828448
	ContestId	:	998
	Index	:	B
	ProblemName	:	Cutting
	ProblemTags	:	['dp', 'greedy', 'sortings']
	ProgrammingLanguage	:	GNU C++17
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 210

int n, b, a[MAXN], ans, cnt;
vector<pair<int, int> > v;

int main() {
	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[i] % 2 == 0)
			cnt++;
		else
			cnt--;
		if (cnt == 0)
			v.push_back({abs(a[i] - a[i + 1]), i});
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		if (b - v[i].first >= 0) {
			ans++;
			b -= v[i].first;
		}
	cout << ans << endl;
}