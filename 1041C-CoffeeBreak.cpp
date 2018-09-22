/*
	SubmissionId	:	42945536
	ContestId	:	1041
	Index	:	C
	ProblemName	:	Coffee Break
	ProblemTags	:	['data structures', 'greedy', 'two pointers']
	ProgrammingLanguage	:	GNU C++17
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int n, m, d, ans, color[MAXN], a[MAXN];
set<pair<int, int> > st;

int main() {
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st.insert(make_pair(a[i], i));
	}
	for (int i = 1; i <= n; i++) {
		if (st.size() == 0)
			break;
		auto p = st.begin();
		pair<int, int> tmp = *p;
		color[tmp.second] = i;
		st.erase(p);
		while (st.upper_bound(make_pair(tmp.first + d + 1, -1)) != st.end()) {
			p = st.upper_bound(make_pair(tmp.first + d + 1, -1));
			tmp = *p;
			color[p->second] = i;
			st.erase(p);
		}
		ans++;
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++)
		cout << color[i] << " ";
	cout << endl;
	return 0;
}