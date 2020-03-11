/*
	SubmissionId	:	21892774
	ContestId	:	730
	Index	:	B
	ProblemName	:	Minimum and Maximum
	ProblemTags	:	['constructive algorithms']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int q, n;
vector<int> mins, maxs;

int main()
{
	cin >> q;
	while(q--)
	{
		cin >> n;
		mins.clear();
		maxs.clear();
		for (int i = 1; i + 1 <= n; i += 2)
		{
			cout << "? " << i << " " << i + 1 << endl;
			fflush(stdout);
			char ch;
			cin >> ch;
			// ch = '<';
			if (ch == '<')
			{
				mins.push_back(i);
				maxs.push_back(i + 1);
			}
			else
			{
				mins.push_back(i + 1);
				maxs.push_back(i);
			}
		}
		if (n & 1)
		{
			mins.push_back(n);
			maxs.push_back(n);
		}
		int minIdx = 0, maxIdx = 0;
		for (int i = 1; i < mins.size(); i++)
		{
			cout << "? " << mins[minIdx] << " " << mins[i] << endl;
			fflush(stdout);
			char ch;
			cin >> ch;
			// ch = '<';
			if (ch != '<')
				minIdx = i;
		}
		for (int i = 1; i < maxs.size(); i++)
		{
			cout << "? " << maxs[maxIdx] << " " << maxs[i] << endl;
			fflush(stdout);
			char ch;
			cin >> ch;
			// ch = '<';
			if (ch != '>')
				maxIdx = i;
		}
		cout << "! " << mins[minIdx] << " " << maxs[maxIdx] << endl;
		fflush(stdout);
	}
	return 0;
}