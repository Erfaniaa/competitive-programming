/*
	SubmissionId	:	3059288
	ContestId	:	268
	Index	:	C
	ProblemName	:	Beautiful Sets of Points
	ProblemTags	:	['constructive algorithms', 'implementation']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>

using namespace std;

int main()
{
    int yy, xx;
    cin >> xx >> yy;
    cout << min(xx, yy) + 1 << endl;
    int y = 0;
    for (int x = min(xx, yy); x >= 0; x--, y++)
        cout << x << " " << y << endl;
}
