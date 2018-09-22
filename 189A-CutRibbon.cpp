/*
	SubmissionId	:	2714228
	ContestId	:	189
	Index	:	A
	ProblemName	:	Cut Ribbon
	ProblemTags	:	['brute force', 'dp']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <iostream>

using namespace std;

int d[100000];

int main()
{
    int n, a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    for (int i = 1; i <= n; i++)
        d[i] = -1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            if (i >= a[j] && d[i - a[j]] > -1)
                d[i] = max(d[i], d[i - a[j]] + 1);
    cout << d[n] << endl;
}
