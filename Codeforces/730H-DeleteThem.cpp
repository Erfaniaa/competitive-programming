/*
	SubmissionId	:	21893247
	ContestId	:	730
	Index	:	H
	ProblemName	:	Delete Them
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, a[210], len;
string s[210], ans;
bool state[210], final[210];

bool match(char ch1, char ch2)
{
	return (ch1 == '?') || (ch1 == ch2); 
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
		a[i]--;
		len = s[a[i]].length();
		final[a[i]] = true;
	}
	for (int i = 0; i < m; i++)
		if (s[a[i]].length() != len)
		{
			cout << "No" << endl;
			return 0;
		}	
	for (int l = 0; l < len; l++)
	{
		char ch = s[a[0]][l];
		char tmp = ch;
		for (int i = 0; i < m; i++)
			if (ch != s[a[i]][l])
				tmp = '?';
		ans.push_back(tmp);
	}
	for (int l = 0; l < len; l++)
	{
		char ch = ans[l];
		for (int i = 0; i < n; i++)
		{
			if (!state[i])
				if (!match(ch, s[i][l]))
					state[i] = true;
		}
	}
	for (int i = 0; i < n; i++)
		if (s[i].length() == len && state[i] == final[i])
		{
			cout << "No" << endl;
			return 0;
		}
	cout << "Yes" << endl << ans << endl;
	return 0;
}