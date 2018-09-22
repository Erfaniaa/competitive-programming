/*
	SubmissionId	:	36843200
	ContestId	:	952
	Index	:	C
	ProblemName	:	Ravioli Sort
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

vector <int> normalize(vector <int> v) {
	for (int i = 0; i < (int)v.size() - 1; i++)
		while (v[i] - v[i + 1] >= 2) {
			v[i]--;
			v[i + 1]++;
		}
	reverse(v.begin(), v.end());
	for (int i = 0; i < (int)v.size() - 1; i++)
		while (v[i] - v[i + 1] >= 2) {
			v[i]--;
			v[i + 1]++;
		}
	reverse(v.begin(), v.end());
	return v;
}

vector <int> removeZeros(vector <int> v) {
	vector <int> ret;
	for (int i = 0; i < v.size(); i++)
		if (v[i] > 0)
			ret.push_back(v[i]);
	return ret;
}

vector <int> removeMax(vector <int> v) {
	vector <int> ret;
	int idx = 0;
	for (int i = 0; i < v.size(); i++)
		if (v[i] > v[idx])
			idx = i;
	for (int i = 0; i < v.size(); i++)
		if (i != idx)
			ret.push_back(v[i]);
	return ret;
}

int main() {
	int n;
	vector <int> v, v2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	vector <int> sorted = v;
	vector <int> reversed = v;
	sort(sorted.begin(), sorted.end());
	sort(reversed.begin(), reversed.end());
	reverse(reversed.begin(), reversed.end());
	for (int i = 1; i <= n; i++) {
		v = normalize(v);
		int mx = *max_element(v.begin(), v.end());
		v2.push_back(mx);
		v2 = normalize(v2);
		v = removeMax(v);
	}
	if (v2 == sorted || v2 == reversed)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}