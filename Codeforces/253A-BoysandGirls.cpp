/*
	SubmissionId	:	2721847
	ContestId	:	253
	Index	:	A
	ProblemName	:	Boys and Girls
	ProblemTags	:	['greedy']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

#define cin fin
#define cout fout
ofstream fout("output.txt");
ifstream fin("input.txt");

#define For(i, a, b) for(typeof(b) i = (a); i <= (b); i++)

int main()
{
	int n, m;
	string s = "";
	cin >> n >> m;
	cout << "";
	if (n > m)
	{
		cout << "";
		For (i, 1, m)
			s += "BG";
		For (i, 1, n - m)
			s += "B";
	}
	else
	{
		For (i, 1, n)
			s += "GB";
		For (i, 1, m - n)
			s += "G";
	}
	cout << s;
	return 0;
}
