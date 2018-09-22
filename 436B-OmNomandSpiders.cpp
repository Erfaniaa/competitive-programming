/*
	SubmissionId	:	6879956
	ContestId	:	436
	Index	:	B
	ProblemName	:	Om Nom and Spiders
	ProblemTags	:	['implementation', 'math']
	ProgrammingLanguage	:	GNU C++0x
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
#define MAXN 2010

int n, m, k;
char a[MAXN][MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
			cin >> a[x][y];
	for (int y = 1; y <= m; y++)
	{
		int ans = 0;
		for (int x = 1; x <= n; x++)
		{
			int t = x - 1;
			ans += (x - t >= 1 && a[x - t][y] == 'D');
			ans += (y - t >= 1 && a[x][y - t] == 'R');
			ans += (x + t <= n && a[x + t][y] == 'U');
			ans += (y + t <= m && a[x][y + t] == 'L');
		}
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}