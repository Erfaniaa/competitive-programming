/*
	SubmissionId	:	5600864
	ContestId	:	2
	Index	:	A
	ProblemName	:	Winner
	ProblemTags	:	['hashing', 'implementation']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;

struct Round
{
       int score;
       string name;
};

int main(int argc, char *argv[])
{
    map<string, int> score;
    Round round[1000];
    int n;
    cin >> n;
    string s[1000];
    int x[1000];
    int max = -1000000000;
    for (int i = 0; i < n ; i ++)
    {
        cin >> s[i] >> x[i];
        score[s[i]] += x[i];
        round[i].name = s[i];
        round[i].score = score[s[i]];
    }
    for (int i = 0; i < n; i ++)
        if (score[s[i]] > max)
           max = score[s[i]];
    for (int i = 0; i < n; i ++)
        if (round[i].score >= max && score[round[i].name] == max)
        {
           cout << round[i].name << endl;
           //system("PAUSE");
           return 0;
        }
}