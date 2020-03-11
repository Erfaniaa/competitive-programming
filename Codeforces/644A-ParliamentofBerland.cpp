/*
	SubmissionId	:	16771715
	ContestId	:	644
	Index	:	A
	ProblemName	:	Parliament of Berland
	ProblemTags	:	['*special', 'constructive algorithms']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, a, b, num[] = {-1, 0};

int main()
{
	cin >> n >> a >> b;
	if (a * b < n)
		cout << -1 << endl;
	else
		for (int i = 1; i <= a; i++)
		{
			for (int j = 1; j <= b; j++)
			{
				if (num[(i + j) % 2] + 2 <= n)
					cout << (num[(i + j) % 2] += 2) << " ";
				else
					cout << 0 << " ";
			}
			cout << endl;
		}
	return 0;
}