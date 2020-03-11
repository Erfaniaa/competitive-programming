/*
	SubmissionId	:	6577578
	ContestId	:	147
	Index	:	B
	ProblemName	:	Smile House
	ProblemTags	:	['binary search', 'graphs', 'matrices']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <cstdio>
#include <iostream>

using namespace std;

#define MAXN 301
#define INF 1000000010

struct Matrix
{
	int a[MAXN][MAXN], sz;
	inline Matrix(int _sz = 0)
	{
		sz = _sz;
		for (int i = 1; i <= sz; i++)
			for (int j = 1; j <= sz; j++)
				a[i][j] = ((i == j) ? 0 : -INF);
	}
	inline Matrix operator * (Matrix &b) const
	{
		Matrix c(sz);
		for (int i = 1; i <= sz; i++)
			for (int j = 1; j <= sz; j++)
			{
				c.a[i][j] = -INF;
				for (int k = 1; k <= sz; k++)
					c.a[i][j] = max(c.a[i][j], a[i][k] + b.a[k][j]);
			}
		return c;
	}
};

int n, m, ans;

int main()
{
	scanf("%d%d", &n, &m);
	Matrix w(n), p[11], t(n);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		scanf("%d%d", &w.a[x][y], &w.a[y][x]);
	}
	p[0] = w;
	for (int i = 1; i <= 8; i++)
		p[i] = p[i - 1] * p[i - 1];
	for (int i = 8; i >= 0; i--)
	{
		Matrix temp = t * p[i];
		bool flag = false;
		for (int j = 1; j <= n; j++)
			if (temp.a[j][j] > 0)
			{
				flag = true;
				break;
			}
		if (!flag)
		{
			t = temp;
			ans += (1 << i);
		}
	}
	if (ans == 511)
		printf("0");
	else
		printf("%d", ans + 1);
	cout << endl;
	return 0;
}