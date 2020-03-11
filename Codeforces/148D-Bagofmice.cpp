/*
	SubmissionId	:	2680042
	ContestId	:	148
	Index	:	D
	ProblemName	:	Bag of mice
	ProblemTags	:	['dp', 'games', 'math', 'probabilities']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>

using namespace std;

double p[1010][1010], d[1010][1010];

int main()
{
    int ww, bb;
    cin >> ww >> bb;
    for (int i = 1; i <= ww; i++)
        p[i][0] = d[i][0] = 1;
    d[0][0] = 1;
    for (double w = 1; w <= ww; w++)
    {
        for (double b = 1; b <= bb; b++)
        {
            p[(int)w][(int)b] = (w / (w + b)) + (b / (w + b)) * (1 - d[(int)w][(int)b - 1]);
            d[(int)w][(int)b] = (w / (w + b));
            //Dragon Draws Black:
            //Black mouse jumps off:
            if (b >= 2)
                d[(int)w][(int)b] += (b / (w + b)) * ((b - 1) / (w + b - 1)) * (1 - p[(int)w][(int)b - 2]);
            //White mouse jumps off:
            d[(int)w][(int)b] += (b / (w + b)) * (w / (w + b - 1)) * (1 - p[(int)w - 1][(int)b - 1]);
        }
    }
    cout.precision(10);
    cout << fixed << p[ww][bb] << endl;
}
