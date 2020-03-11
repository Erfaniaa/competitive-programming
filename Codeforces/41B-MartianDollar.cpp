/*
	SubmissionId	:	5600969
	ContestId	:	41
	Index	:	B
	ProblemName	:	Martian Dollar
	ProblemTags	:	['brute force']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>

#define sz(x) ((int)(x.size()))

using namespace std;

int main()
{
    int n, b;
    cin >> n >> b;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int max = b;
    for (int i = 0; i < n; i++)
    {
        int tmp = b % a[i], num = b / a[i];
        int maxP = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > maxP)
                maxP = a[j];
        }
        tmp = maxP * num + tmp;
        if (tmp > max)
            max = tmp;
    }
    cout << max << endl;
    return 0;
}