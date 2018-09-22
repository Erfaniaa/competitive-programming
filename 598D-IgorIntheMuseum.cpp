/*
	SubmissionId	:	14760666
	ContestId	:	598
	Index	:	D
	ProblemName	:	Igor In the Museum
	ProblemTags	:	['dfs and similar']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <iostream>

using namespace std;

int dx[] = {0, 0, -1, +1};
int dy[] = {-1, +1, 0, 0};
bool mark[1010][1010];
char a[1010][1010];
int n, m, q, ans[1010][1010];

pair<int, int> par[1010][1010];

pair<int, int> find(int x, int y)
{
	//cout << "Find " << x << " --- " << y << endl;
	//cin.get();
	//cin.get();
	if (par[x][y] == make_pair(0, 0))
		return make_pair(x, y);
	pair<int, int> f = par[x][y];
	return par[x][y] = find(f.first, f.second);
}

int dfs(int x, int y)
{
	int ret = 0;
	mark[x][y] = true;
	//cout << x << "-" << y << endl;
	for (int k = 0; k < 4; k++)
	{
		int x2 = x + dx[k];
		int y2 = y + dy[k];
		if (x2 > n || x2 < 1 || y2 > m || y2 < 1)
			continue;
		ret += (a[x2][y2] == '*');
		if (!mark[x2][y2] && a[x2][y2] == '.')
		{ 
			par[x2][y2] = find(x, y);
			ret += dfs(x2, y2);
		}
	}
	return ans[x][y] = ret;
}

int main()
{
	cin >> n >> m >> q; //n x m
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] == '.' && !mark[i][j])
			{
				//cout << i << " " << j << endl;
				dfs(i, j);
			}
	while (q--)
	{
		int xx, yy;
		cin >> xx >> yy;
		pair<int, int> f = find(xx, yy);
		cout << ans[f.first][f.second] << endl;
	}
}