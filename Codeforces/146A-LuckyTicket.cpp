/*
	SubmissionId	:	5600650
	ContestId	:	146
	Index	:	A
	ProblemName	:	Lucky Ticket
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int n, a[3] = {0};
    cin>>n;
    string s;
    cin>>s;
    int i;
    for (i = 0; i < n / 2; i++)
    {
        if (s[i] != '4' && s[i] != '7')
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else
        {
            if (s[i] == '4')
                a[1]++;
            else
                a[2]++;
        }
    }
    for (; i < n; i++)
    {
        if (s[i] != '4' && s[i] != '7')
        {
            cout<<"NO"<<endl;
            return 0;
        }
        else
        {
            if (s[i] == '4')
                a[1]--;
            else
                a[2]--;
        }
    }
    if (a[1] == 0 && a[2] == 0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}