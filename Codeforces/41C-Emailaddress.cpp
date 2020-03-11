/*
	SubmissionId	:	5600972
	ContestId	:	41
	Index	:	C
	ProblemName	:	Email address
	ProblemTags	:	['expression parsing', 'implementation']
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
    string s;
    cin >> s;
    cout << s[0];
    bool b = false, zer = false;
    for (int i = 1; i < (int) s.size() - 1; i++)
    {
        if (s[i] == 'a' && s[i + 1] == 't' && !b)
        {
            cout << "@";
            i += 1;
            b = true;
        }
        else if(s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 't' && i != s.size() - 3)
        {
             cout << ".";
             i += 2;
        }
        else
            cout << s[i];
    }
    cout << s[(int)s.size() - 1];
    cout << endl;
    return 0;
}