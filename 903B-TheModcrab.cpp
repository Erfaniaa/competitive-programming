/*
	SubmissionId	:	33197202
	ContestId	:	903
	Index	:	B
	ProblemName	:	The Modcrab
	ProblemTags	:	['greedy', 'implementation']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

long long h1, a1, c1, h2, a2;
vector<string> v;

int main()
{
	cin >> h1 >> a1 >> c1;
	cin >> h2 >> a2;
	while (h2 > 0)
	{
		if (h1 - a2 <= 0 && h2 > a1)
		{
			v.push_back("HEAL");
			h1 += c1;
		}
		else
		{
			v.push_back("STRIKE");
			h2 -= a1;
		}
		if (h2 <= 0)
			break;
		h1 -= a2;
	}
	cout << v.size() << endl;
	for (auto s: v)
		cout << s << endl;
	return 0;
}