/*
	SubmissionId	:	15653491
	ContestId	:	618
	Index	:	B
	ProblemName	:	Guess the Permutation
	ProblemTags	:	['constructive algorithms']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF (1000 * 1000 * 1000)
#define MAXN 55

int n, a[MAXN][MAXN], p[MAXN];
bool mark[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			bool b = true, found = false;
			for (int j = 1; j <= n; j++)
			{
				if (a[i][j] == k)
					found = true;
				if (!mark[i] && !mark[j] && a[i][j] != 0 && a[i][j] != k)
				{
					b = false;
					break;
				}
			}
			if (b && found)
			{
				p[i] = k;
				mark[i] = true;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (p[i] == 0)
			p[i] = n;
	for (int i = 1; i <= n; i++)
		cout << p[i] << " ";
	return 0;
}