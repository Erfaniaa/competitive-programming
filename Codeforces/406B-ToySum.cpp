/*
	SubmissionId	:	6113019
	ContestId	:	406
	Index	:	B
	ProblemName	:	Toy Sum
	ProblemTags	:	['constructive algorithms', 'greedy']
	ProgrammingLanguage	:	GNU C++0x
	Verdict	:	OK
*/

#include <cstdio>
using namespace std;

#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 1000010
#define S 1000000

int mark[MAXN], k, cnt, n;

int main()
{
	//int ans1 = 0, ans2 = 0;
	scanf("%d", &n);
	FOR (i, 1, n)
	{
		int a;
		scanf("%d", &a);
		//ans1 += a - 1;
		mark[a] = 1;
	}
	FOR (a, 1, S)
	{
		if (a < (S - a + 1) && mark[a] == 1 && mark[S - a + 1] == 1)
			k++;
		if (mark[a] == 1 && mark[S - a + 1] == 0)
			mark[S - a + 1] = 2;
	}
	FOR (a, 1, S)
		if (k > 0 && mark[a] == 0 && mark[S - a + 1] == 0)
		{
			k--;
			mark[a] = mark[S - a + 1] = 2;
		}
	FOR (i, 1, S)
		if (mark[i] == 2)
			cnt++;
	printf("%d\n", cnt);
	FOR (i, 1, S)
		if (mark[i] == 2)
		{
			printf("%d ", i);
			//ans2 += S - i;
		}
	//printf("\n%d %d", ans1, ans2);
	return 0;
}