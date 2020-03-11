/*
	SubmissionId	:	20878209
	ContestId	:	719
	Index	:	C
	ProblemName	:	Efim and Strange Grade
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, t;
string s, s1, s2;

int main()
{
	cin >> n >> t;
	cin >> s;
	int p = s.find(".");
	s1 = s.substr(0, p);
	s2 = s.substr(p + 1, s.length() - p);
	for (int i = 0; i < s2.length(); i++)
	{
		if (s2[i] >= '5')
		{
			while (s2.length() != i + 1)
				s2.pop_back();
			i--;
			while (t > 0 && i >= 0 && s2[i + 1] >= '5')
			{
				s2.pop_back();
				s2[i]++;
				t--;
				int j = i;
				while (j >= 1 && s2[j] == '9' + 1)
				{
					s2[j - 1]++;
					s2[j] = '0';
				}
				i--;
			}
			if (t > 0 && s2[0] >= '5')
			{
				s2[0] = '0';
				s1[s1.length() - 1]++;
				int j = s1.length() - 1;
				while (j >= 1 && s1[j] == '9' + 1)
				{
					s1[j - 1]++;
					s1[j] = '0';
					j--;
				}
			}
			break;
		}
	}
	if (s2[0] == '9' + 1)
	{
		int j = s1.length() - 1;
		while (j >= 1 && s1[j] == '9' + 1)
		{
			s1[j - 1]++;
			s1[j] = '0';
			j--;
		}
	}
	if (s1[0] == '9' + 1)
	{
		s1[0] = '0';
		s1 = "1" + s1;
	}
	while (s2.size() > 1 && s2[s2.size() - 1] == '0')
		s2.pop_back();
	if (s2 != "0")
		cout << s1 << "." << s2 << endl;
	else
		cout << s1 << endl;
	return 0;
}