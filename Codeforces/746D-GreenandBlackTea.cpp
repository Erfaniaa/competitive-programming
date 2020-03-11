/*
	SubmissionId	:	23094019
	ContestId	:	746
	Index	:	D
	ProblemName	:	Green and Black Tea
	ProblemTags	:	['constructive algorithms', 'greedy']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int n, x[MAXN], y[MAXN], rem, dv;
long long a, b, k;
bool found;

int main()
{
	cin >> n >> k >> a >> b;
	int pp = -1, qq = -1;
	for (int p = 0; p <= n && !found; p++)
		for (int q = p - 1; q <= p + 1; q++)
			if (p + q >= 1)
				if (a >= p && a <= k * p && b >= q && b <= k * q)
				{
					found = true;
					pp = p;
					qq = q;
					break;
				}
	if (!found)
	{
		cout << "NO" << endl;
		return 0;
	}
	if (pp > 0)
	{
		rem = a % pp;
		dv = a / pp;
		for (int i = 0; i < pp; i++)
		{
			x[i] = dv;
			if (i < rem)
				x[i]++;
		}
	}
	if (qq > 0)
	{
		rem = b % qq;
		dv = b / qq;
		for (int i = 0; i < qq; i++)
		{
			y[i] = dv;
			if (i < rem)
				y[i]++;
		}
	}
	if (pp == qq)
		for (int i = 0; i < pp; i++)
		{
			cout << string(x[i], 'G');
			cout << string(y[i], 'B');
		}
	if (pp < qq)
	{
		cout << string(y[0], 'B');
		for (int i = 0; i < pp; i++)
		{
			cout << string(x[i], 'G');
			cout << string(y[i + 1], 'B');
		}
	}
	if (pp > qq)
	{
		for (int i = 0; i < pp - 1; i++)
		{
			cout << string(x[i], 'G');
			cout << string(y[i], 'B');
		}
		cout << string(x[pp - 1], 'G');
	}
	return 0;
}