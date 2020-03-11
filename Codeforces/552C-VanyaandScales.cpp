/*
	SubmissionId	:	13410339
	ContestId	:	552
	Index	:	C
	ProblemName	:	Vanya and Scales
	ProblemTags	:	['brute force', 'dp', 'greedy', 'math', 'meet-in-the-middle']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int w, m;

/*bool canMake(long long x, long long mask)
{
	if (x < 0)
		return false;
	if (x == 0)
		return true;
	if (b.find(x))
		return b[x];
	for (int i = 0; i < cnt; i++)
		if ((mask & (1ll << i)) == 0)
			if (canMake(x - p[i], mask + (1ll << i)))
				return b[x] = true;
	return b[x] = false;
}*/

inline bool canMake(int x)
{
	if (x == 0)
		return true;
	if (x % w == 0)
		return canMake(x / w);
	else if ((x - 1) % w == 0)
		return canMake((x - 1) / w);
	else if ((x + 1) % w == 0)
		return canMake((x + 1) / w);
	else
		return false;
}

int main()
{
	cin >> w >> m;
	/*p[0] = 1;
	for (cnt = 1; cnt <= 100; cnt++)
	{
		if (p[cnt - 1] * w <= m)
			p[cnt] = p[cnt - 1] * w;
		else
			break;
	}
	for (int mask = 1; mask < ())*/
	if (canMake(m))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}