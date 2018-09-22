/*
	SubmissionId	:	28217950
	ContestId	:	822
	Index	:	B
	ProblemName	:	Crossword solving
	ProblemTags	:	['brute force', 'implementation', 'strings']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

string s, t;
int maxIdx, x, mx;
vector<int> v;

int main()
{
	cin >> x >> x;
	cin >> s >> t;
	for (int i = 0; i <= (int)t.size() - (int)s.size(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < s.size(); j++)
			cnt += s[j] == t[i + j];
		if (cnt > mx)
		{
			mx = cnt;
			maxIdx = i;
		}
	}
	for (int i = maxIdx; i < maxIdx + (int)s.size(); i++)
		if (s[i - maxIdx] != t[i])
			v.push_back(i - maxIdx + 1);
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}