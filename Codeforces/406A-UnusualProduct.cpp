/*
	SubmissionId	:	6109254
	ContestId	:	406
	Index	:	A
	ProblemName	:	Unusual Product
	ProblemTags	:	['implementation', 'math']
	ProgrammingLanguage	:	GNU C++0x
	Verdict	:	OK
*/

#include <cstdio>
using namespace std;

#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

int n, q, ans;

int main()
{
	scanf("%d", &n);
	FOR (i, 1, n)
		FOR (j, 1, n)
		{
			int a;
			scanf("%d", &a);
			if (i == j)
				ans += a;
		}
	scanf("%d", &q);
	ans = ans % 2;
	FOR (i, 1, q)
	{
		int t, t2;
		scanf("%d", &t);
		if (t == 3)
			printf("%d", ans);
		else
		{
			scanf("%d", &t2);
			ans = 1 - ans;
		}
	}
	return 0;
}