/*
	SubmissionId	:	5600939
	ContestId	:	109
	Index	:	A
	ProblemName	:	Lucky Sum of Digits
	ProblemTags	:	['brute force', 'implementation']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>> n;
    for (int l = 1; l <= n; l++)
    {
        int rem = n - 4 * l;
        if (rem < 0)
            break;
        if (rem % 3 != 0) continue;
        int sevens = rem / 3;
        if (sevens > l) continue;
        for (int i = l - sevens; i > 0; i--) cout << 4;
        for (int i = sevens; i > 0; i--) cout << 7;
        return 0;
    }
    cout << -1;

}