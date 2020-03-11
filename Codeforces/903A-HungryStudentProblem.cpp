/*
	SubmissionId	:	33159857
	ContestId	:	903
	Index	:	A
	ProblemName	:	Hungry Student Problem
	ProblemTags	:	['greedy', 'implementation']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, x;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		bool valid = false;
		for (int a = 0; a <= x; a++)
			for (int b = 0; b <= x; b++)
				if (3 * a + 7 * b == x)
					valid = true;
		if (valid)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}