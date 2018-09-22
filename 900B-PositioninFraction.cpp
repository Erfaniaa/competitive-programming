/*
	SubmissionId	:	33119430
	ContestId	:	900
	Index	:	B
	ProblemName	:	Position in Fraction
	ProblemTags	:	['math']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

long long a, b, c, q;

#define MAXDIG 1000020

int main()
{
	cin >> a >> b >> c;
	for (int i = 0; i <= MAXDIG; i++)
	{
		q = a / b;
		a %= b;
		a *= 10ll;
		if (q == c && i > 0)
		{
			cout << i << endl;
			return 0;
		}
		while (a < b)
		{
			i++;
			q = 0;
			if (q == c && i > 0)
			{
				cout << i << endl;
				return 0;
			}
			a *= 10;
			if (i >= MAXDIG)
				break;
		}
	}
	cout << -1 << endl;
	return 0;
}