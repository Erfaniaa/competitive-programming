/*
	SubmissionId	:	40275875
	ContestId	:	1008
	Index	:	B
	ProblemName	:	Turn the Rectangles
	ProblemTags	:	['greedy', 'sortings']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, x[100010], y[100010];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	bool ans1 = true;
	bool ans2 = true;
	for (int i = 1; i < n; i++) {
		if (x[i] > y[i])
			swap(x[i], y[i]);
		if (y[i] > y[i - 1])
			swap(x[i], y[i]);
		else
			continue;
		if (y[i] > y[i - 1])
			ans1 = false;
	}
	swap(x[0], y[0]);
	for (int i = 1; i < n; i++) {
		if (x[i] > y[i])
			swap(x[i], y[i]);
		if (y[i] > y[i - 1])
			swap(x[i], y[i]);
		else
			continue;
		if (y[i] > y[i - 1])
			ans2 = false;
	}
	if (ans1 || ans2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}