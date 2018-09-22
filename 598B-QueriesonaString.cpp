/*
	SubmissionId	:	14759175
	ContestId	:	598
	Index	:	B
	ProblemName	:	Queries on a String
	ProblemTags	:	['implementation', 'strings']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <iostream>

using namespace std;

string s;
int m;

int main()
{
	cin >> s;
	cin >> m;
	while (m--)
	{
		int l, r, k;
		cin >> l >> r >> k;
		long long len = r - l + 1;
		l--;
		r--;
		string s2 = s;
		for (int i = l; i <= r; i++)
			s[i] = s2[((i - l) - k + 10000000 * len) % len + l];
	}
	cout << s << endl;
	return 0;
}