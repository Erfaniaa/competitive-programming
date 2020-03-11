/*
	SubmissionId	:	6795907
	ContestId	:	284
	Index	:	C
	ProblemName	:	Cows and Sequence
	ProblemTags	:	['constructive algorithms', 'data structures', 'dp']
	ProgrammingLanguage	:	GNU C++0x
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int len, q, type;
long long sum, dif[MAXN], b[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	len = 1;
	cin >> q;
	while (q--)
	{
		cin >> type;
		if (type == 1)
		{
			int a;
			long long x;
			cin >> a >> x;
			sum += a * x;
			dif[a] += x;
		}
		else if (type == 2)
		{
			int x;
			cin >> x;
			len++;
			sum += x;
			b[len] = x;
		}
		else
		{
			sum -= (b[len] + dif[len]);
			dif[len - 1] += dif[len];
			dif[len] = 0;
			len--;
		}
		printf("%.7lf\n", sum / (double)len);
	}
	return 0;
}