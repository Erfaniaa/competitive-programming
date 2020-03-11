/*
	SubmissionId	:	5600869
	ContestId	:	61
	Index	:	A
	ProblemName	:	Ultra-Fast Mathematician
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    for (int i = 0; i < s1.length(); i ++)
        if (s1[i] != s2[i])
           cout << "1";
        else
            cout << "0";
    cout << endl;
    //system("PAUSE");
}