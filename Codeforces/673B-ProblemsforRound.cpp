/*
	SubmissionId	:	17790693
	ContestId	:	673
	Index	:	B
	ProblemName	:	Problems for Round
	ProblemTags	:	['greedy', 'implementation']
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
#define MAXN 100010

int n, m, wRight, bLeft, color[MAXN], sum[MAXN];
vector <int> adj[MAXN];
bool invalid;

void dfs(int v, int c)
{
	if (invalid)
		return;
	if ((c == 0 && v >= bLeft) || (c == 1 && v <= wRight))
	{
		invalid = true;
		return;
	}
	if (color[v] != -1 && color[v] != c)
	{
		invalid = true;
		return;
	}
	color[v] = c;
	if (c == 0)
		wRight = max(wRight, v);
	if (c == 1)
		bLeft = min(bLeft, v);
	if (wRight >= bLeft)
	{
		invalid = true;
		return;
	}
	for (auto u: adj[v])
		if (!(color[u] != -1 && color[u] == 1 - c))
			dfs(u, 1 - c);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	wRight = 1;
	bLeft = n;
	memset(color, -1, sizeof color);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + (int)adj[i].size();
	int i = 1, j = n;
	while (1)
	{
		for (; i <= wRight; i++)
		{
			dfs(i, 0);
			if (invalid)
			{
				cout << 0 << endl;
				return 0;
			}
		}
		for (; j >= bLeft; j--)
		{
			dfs(j, 1);
			if (invalid)
			{
				cout << 0 << endl;
				return 0;
			}
		}
		if (i <= wRight || j >= bLeft)
			continue;
		if (j <= i)
			break;
		if (sum[j] - sum[i - 1] == 0)
			break;
		dfs(i, 0);
		if (invalid)
		{
			cout << 0 << endl;
			return 0;
		}
		dfs(j, 1);
		if (invalid)
		{
			cout << 0 << endl;
			return 0;
		}
	}
	cout << max(bLeft - wRight, 0) << endl;
	return 0;
}