/*
	SubmissionId	:	3888552
	ContestId	:	318
	Index	:	B
	ProblemName	:	Strings of Power
	ProblemTags	:	['implementation', 'strings', 'two pointers']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>

using namespace std;

int c[1000010];

int main()
{
    string s;
    cin >> s;
    long long ans = 0;
    if ((int)s.length() < 5)
    {
        cout << 0 << endl;
        return 0;
    }
    string s2 = s.substr(0, 5);
    if (s2 == "heavy")
        c[4] = 1;
    for (int i = 5; i < (int)s.length(); i++)
    {
        s2.erase(0, 1);
        s2 += s[i];
        if (s2 == "heavy")
            c[i] = c[i - 1] + 1;
        else
            c[i] = c[i - 1];
    }

    s2 = s.substr(0, 5);
    for (int i = 5; i < (int)s.length(); i++)
    {
        s2.erase(0, 1);
        s2 += s[i];
        if (s2 == "metal")
            ans += (long long)c[i];
    }
    cout << ans << endl;
    return 0;
}
