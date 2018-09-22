/*
	SubmissionId	:	5600657
	ContestId	:	146
	Index	:	B
	ProblemName	:	Lucky Mask
	ProblemTags	:	['brute force', 'implementation']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <cstdlib>
#include <iostream>
#include <string>
//#include <conio.h>

using namespace std;

bool mask(string s, string s2)
{
    long long j = 0;
    for (long long i = 0; i < s.length(); i++)
        if (s[i] == '4' || s[i] == '7')
        {
            if (s[i] == s2[j])
                j++;
            else
                return false;
        }
    return (j == s2.length());
}

int main(long long argc, char *argv[])
{
    long long a, b;
    cin>>a>>b;
    char sa[20];
    itoa(b, sa, 10);
    string sa2 = sa;
    long long i;
    for (i = a + 1; ; i++)
    {
        char s[20];
        itoa(i, s, 10);
        string s2 = s;
        if (mask(s2, sa2))
            break;
    }
    cout<<i<<endl;
    //getch();
}