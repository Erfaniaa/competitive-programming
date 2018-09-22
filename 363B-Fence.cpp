/*
	SubmissionId	:	5078660
	ContestId	:	363
	Index	:	B
	ProblemName	:	Fence
	ProblemTags	:	['brute force', 'dp']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>

using namespace std;

int sum[200010];

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }
    int mn = k;
    for(int i = k; i <= n; i++)
        if (sum[i] - sum[i - k] < sum[mn] - sum[mn - k])
            mn = i;
    cout << mn - k + 1 << endl;
}