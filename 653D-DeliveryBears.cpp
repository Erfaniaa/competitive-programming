/*
	SubmissionId	:	16817324
	ContestId	:	653
	Index	:	D
	ProblemName	:	Delivery Bears
	ProblemTags	:	['binary search', 'flows', 'graphs']
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
#define MAXN 51

int n, m, x;
int f[MAXN][MAXN], wei[MAXN][MAXN], firstWei[MAXN][MAXN];
bool mark[MAXN];

int dfs(int st, int en, int mn)
{
	if (st == en)
		return mn;
	mark[st] = true;
	for (int i = 1; i <= n; i++)
		if (!mark[i] && wei[st][i] > 0 && wei[st][i] > 0)
		{
			int send = dfs(i, en, min(mn, wei[st][i]));
			if (send > 0)
			{
				f[st][i] += send;
				f[i][st] -= send;
				wei[st][i] -= send;
				wei[i][st] += send;
				return send;
			}
		}
	return 0;
}

bool check(double k)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			f[i][j] = 0;
			wei[i][j] = (int)min(firstWei[i][j] / k, (double)INF);
		}
	while (1)
	{
		memset(mark, 0, sizeof mark);
		int tmp = dfs(1, n, INF);
		if (tmp == 0)
			break;
		cnt += tmp;
	}
	return cnt >= x;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> x;
	for (int i = 1; i <= m; i++)
	{
		int v, u, w;
		cin >> u >> v >> w;
		firstWei[u][v] = w;
	}
	double l = 0, r = (1ll << 60);
	for (int t = 1; t <= 100; t++)
	{
		double mid = (l + r) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid;
	}
	cout.precision(10);
	cout << fixed << l * x << endl;
	return 0;
}