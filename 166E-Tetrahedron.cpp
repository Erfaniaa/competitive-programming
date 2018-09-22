/*
	SubmissionId	:	2714377
	ContestId	:	166
	Index	:	E
	ProblemName	:	Tetrahedron
	ProblemTags	:	['dp', 'math', 'matrices']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>

using namespace std;

long long d[10000001], c[10000001];

int main()
{
    int n;
    cin >> n;
    c[0] = 0;
    c[1] = 1;
    d[0] = 1;
    d[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        d[i] = (3 * (c[i - 1] % 1000000007)) % 1000000007;
        c[i] = ((d[i - 1] % 1000000007) + (2 * c[i - 1] % 1000000007)) % 1000000007;
    }
    cout << d[n] % 1000000007 << endl;
}
