/*
	SubmissionId	:	38158717
	ContestId	:	978
	Index	:	A
	ProblemName	:	Remove Duplicates
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

int cnt[MAXN], n, a[MAXN];
vector<int> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = n - 1; i >= 0; i--) {
		cnt[a[i]]++;
		if (cnt[a[i]] == 1)
			v.push_back(a[i]);
	}
	cout << v.size() << endl;
	for (int i = (int)v.size() - 1; i >= 0; i--)
		cout << v[i] << " ";
	return 0;
}