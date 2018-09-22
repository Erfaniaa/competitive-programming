/*
	SubmissionId	:	22882940
	ContestId	:	725
	Index	:	C
	ProblemName	:	Hidden Word
	ProblemTags	:	['brute force', 'constructive algorithms', 'implementation']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

string s;
int cnt[30], idx[30], len2, pos;
char ch, ans[2][13];

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		cnt[s[i]]++;
		if (cnt[s[i]] == 2)
		{
			len2 = i - idx[s[i]] - 1;
			if (len2 == 0)
			{
				cout << "Impossible" << endl;
				return 0;
			}
			ch = s[i];
			pos = idx[s[i]];
		}
		idx[s[i]] = i;
	}
	int x = 12 - len2 / 2;
	int y = 0;
	int dx = 1;
	for (int i = 0; i < 26; i++)
	{
		if (x == 13)
		{
			x = 12;
			y = 1;
			dx *= -1;
		}
		if (x == -1)
		{
			x = 0;
			y = 0;
			dx *= -1;
		}
		ans[y][x] = s[pos];
		x += dx;
		pos = (pos + 1) % s.size();
		if (s[pos] == ch)
			pos = (pos + 1) % s.size();
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 13; j++)
			cout << ans[i][j];
		cout << endl;
	}
	return 0;
}