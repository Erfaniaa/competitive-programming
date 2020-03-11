/*
	SubmissionId	:	20843533
	ContestId	:	719
	Index	:	B
	ProblemName	:	Anatoly and Cockroaches
	ProblemTags	:	['greedy']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, r1, b1, r2, b2;
string s, t1, t2;
char ch[2] = {'r', 'b'};

int main()
{
	cin >> n;
	cin >> s;
	t1 = t2 = s;
	for (int i = 0; i < n; i++)
	{
		t1[i] = ch[i & 1];
		t2[i] = ch[1 - (i & 1)];
	}
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'r' && s[i] != t1[i])
			r1++;
		if (s[i] == 'b' && s[i] != t1[i])
			b1++;
		if (s[i] == 'r' && s[i] != t2[i])
			r2++;
		if (s[i] == 'b' && s[i] != t2[i])
			b2++;
	}
	cout << min(max(r1, b1), max(r2, b2)) << endl;
	return 0;
}