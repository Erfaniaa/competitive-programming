/*
	SubmissionId	:	5600964
	ContestId	:	41
	Index	:	A
	ProblemName	:	Translation
	ProblemTags	:	['implementation', 'strings']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include <algorithm>

#define sz(x) ((int)(x.size()))

using namespace std;

int main()
{
    string s, s2, s3;
    cin >> s >> s2;
    s3 = s;
    reverse(s3.begin(), s3.end());
    if (s2 == s3)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}