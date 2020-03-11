/*
	SubmissionId	:	5600882
	ContestId	:	82
	Index	:	A
	ProblemName	:	Double Cola
	ProblemTags	:	['implementation', 'math']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <iostream>
#include <string>

using namespace std;

string s[6] = {"", "Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main()
{
    long long n;
    cin >> n;
    long long a = 1, y = 1;
    while (5 * (2 * y - 1) < n)
    {
        y *= 2;
        //cout << a << " " << y << endl;
    }
    a = y;
    //y = 5 * (2 * y - 1);
    y = (y - 1) * 5;
    //cout << y << endl; 
    long long x = n - y;
    //cout << x << " " << y << endl;
    //cout << a << endl;
    if (x % a == 0)
        cout << s[x / a] << endl;
    else
        cout << s[x / a + 1] << endl;
}