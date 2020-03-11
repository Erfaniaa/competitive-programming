/*
	SubmissionId	:	23085560
	ContestId	:	746
	Index	:	B
	ProblemName	:	Decoding
	ProblemTags	:	['implementation', 'strings']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector<int> a, b;

int main()
{
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
		a.push_back(i);
	for (int i = 0; i < n; i++)
	{
		b.push_back(*(a.begin() + (a.size() / 2)));
		a.erase(a.begin() + (a.size() / 2));
	}
	string ans = s;
	for (int i = 0; i < n; i++)
		ans[b[i]] = s[i];
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}