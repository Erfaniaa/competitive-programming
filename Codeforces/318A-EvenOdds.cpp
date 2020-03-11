/*
	SubmissionId	:	3885061
	ContestId	:	318
	Index	:	A
	ProblemName	:	Even Odds
	ProblemTags	:	['math']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long m = (n + 1) / 2;
    if (k <= m)
        cout << 2 * k - 1 << endl;
    else
        cout << 2 * (k - m) << endl;
}
