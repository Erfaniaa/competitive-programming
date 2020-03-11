/*
	SubmissionId	:	13454520
	ContestId	:	584
	Index	:	C
	ProblemName	:	Marina and Vasya
	ProblemTags	:	['constructive algorithms', 'greedy']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <iostream>

using namespace std;

int n, t, e, d;
string s1, s2, ans;

char New(char ch1, char ch2)
{
	for (int i = (int)'a'; i <= (int)'z'; i++)
		if ((char)i != ch1 && (char)i != ch2)
			return i;
}

int main()
{
	cin >> n >> t;
	cin >> s1 >> s2;
	ans = string(n, '?');
	for (int i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			d++;
		else
			e++;
	}
	for (int d1 = 0; d1 <= min(t, d); d1++)
	{
		int d2 = d1;
		int d3 = d - d1 - d2;
		int e2 = t - d1 - d3;
		int e1 = e - e2;
		if (d3 < 0 || e2 < 0 || e1 < 0)
			continue;
		for (int i = 0; i < n; i++)
		{
			if (s1[i] != s2[i])
			{
				if (d1)
				{
					ans[i] = s2[i];
					d1--;
				}
				else if (d2)
				{
					ans[i] = s1[i];
					d2--;
				}
				else
					ans[i] = New(s1[i], s2[i]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (s1[i] == s2[i])
			{
				if (e2)
				{
					ans[i] = New(s1[i], s2[i]);
					e2--;
				}
				else
					ans[i] = s1[i];
			}
		}	
		break;
	}
	for (int i = 0; i < (int)ans.length(); i++)
		if (ans[i] == '?')
		{
			cout << -1 << endl;
			return 0;
		}
	cout << ans << endl;
	return 0;
}
/*
5 2
aaaab
baaaa
*/