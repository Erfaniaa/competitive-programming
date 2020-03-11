/*
	SubmissionId	:	19750729
	ContestId	:	663
	Index	:	A
	ProblemName	:	Rebus
	ProblemTags	:	['constructive algorithms', 'expression parsing', 'greedy', 'math']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, pos, neg, idx;
vector<char> op;
bool posIdx[210];

bool isValid(int value, int cnt)
{
	return (cnt == 0) || ((value >= cnt) && (value <= cnt * n));
}

int main()
{
	posIdx[0] = true;
	pos = 1;
	while (1)
	{
		char ch1, ch2;
		cin >> ch1 >> ch2;
		if (ch2 == '=')
			break;
		else
		{
			op.push_back(ch2);
			if (ch2 == '+')
			{
				posIdx[++idx] = true;
				pos++;
			}
			if (ch2 == '-')
			{
				posIdx[++idx] = false;
				neg++;
			}
		}
	}
	cin >> n;
	for (int x = 1; x <= 2 * n + 210; x++)
		if (isValid(x, pos) && isValid(x - n, neg))
		{
			int y = x - n;
			int tmpPos = pos, tmpNeg = neg;
			if (!pos)
				continue;
			if (neg == 0 && x != n)
				continue;
			if (!pos)
				pos++;
			if (!neg)
				neg++;
			int posMod = x % pos, negMod = y % neg;
			cout << "Possible" << endl;
			for (int i = 0; i <= idx; i++)
			{
				if (posIdx[i])
				{
					if (i)
						cout << "+ ";
					if (tmpPos <= posMod)
						cout << (x + pos - 1) / pos << " ";
					else
						cout << x / pos << " ";
					tmpPos--;
				}
				else
				{
					cout << "- ";
					if (tmpNeg <= negMod)
						cout << (y + neg - 1) / neg << " ";
					else
						cout << y / neg << " ";
					tmpNeg--;
				}
			}
			cout << "= " << n << endl;
			return 0;
		}
	cout << "Impossible" << endl;
	return 0;
}