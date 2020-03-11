/*
	SubmissionId	:	18370545
	ContestId	:	620
	Index	:	B
	ProblemName	:	Grandfather Dovlet’s calculator
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int a, b, ans;
int cnt[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
//           0  1  2  3  4  5  6  7  8
int main()
{
	cin >> a >> b;
	for (int i = a; i <= b; i++)
	{
		int tmp = i;
		while (tmp)
		{
			ans += cnt[tmp % 10];
			tmp /= 10;
		}
	}
	cout << ans << endl;
	return 0;
}