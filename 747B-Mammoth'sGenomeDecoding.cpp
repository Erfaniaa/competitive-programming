/*
	SubmissionId	:	23120251
	ContestId	:	747
	Index	:	B
	ProblemName	:	Mammoth's Genome Decoding
	ProblemTags	:	['implementation', 'strings']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, cnt[310], dv;
string s;

int main()
{
	cin >> n;
	cin >> s;
	if (n % 4 != 0)
	{
		cout << "===" << endl;
		return 0;
	}
	dv = n / 4;
	for (int i = 0; i < n; i++)
		cnt[s[i]]++;
	if (cnt['A'] > dv || cnt['T'] > dv || cnt['C'] > dv || cnt['G'] > dv)
	{
		cout << "===" << endl;
		return 0;
	}
	if (dv - cnt['A'] + dv - cnt['T'] + dv - cnt['C'] + dv - cnt['G'] != cnt['?'])
	{
		cout << "===" << endl;
		return 0;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '?')
		{
			if (dv - cnt['A'] > 0)
				s[i] = 'A';
			else if (dv - cnt['T'] > 0)
				s[i] = 'T';
			else if (dv - cnt['C'] > 0)
				s[i] = 'C';
			else if (dv - cnt['G'] > 0)
				s[i] = 'G';
			cnt['?']--;
			cnt[s[i]]++;
		}
	}
	cout << s << endl;
	return 0;
}