/*
	SubmissionId	:	15238487
	ContestId	:	615
	Index	:	A
	ProblemName	:	Bulbs
	ProblemTags	:	['implementation']
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
#define MAXN 1010

int cnt[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x;
		for (int j = 1; j <= x; j++)
		{
			cin >> y;
			cnt[y] = 1;
		}
	}
	for (int i = 1; i <= m; i++)
		sum += cnt[i];
	if (sum == m)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}