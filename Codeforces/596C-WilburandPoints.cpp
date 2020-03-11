/*
	SubmissionId	:	14288787
	ContestId	:	596
	Index	:	C
	ProblemName	:	Wilbur and Points
	ProblemTags	:	['greedy', 'sortings']
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

struct Cmp
{
	bool operator() (pii p, pii q)
	{
		if (p.second - p.first != q.second - q.first)
			return (p.second - p.first) < (q.second - q.first);
		return p < q;
	}
} cmp;

vector<pii> points, ans, w;
set<pii> s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
		ans.push_back(make_pair(x, y));
	}
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		w.push_back(make_pair(a, i));
	}
	sort(points.begin(), points.end(), cmp);
	sort(w.begin(), w.end());
	for (int i = 0; i < n; i++)
		if (points[i].Y - points[i].X != w[i].X)
		{
			cout << "NO" << endl;
			return 0;
		}
		else
		{
			ans[w[i].Y] = points[i];
		}
	for (int i = 0; i < n; i++)
	{
		s.insert(ans[i]);
		if (ans[i].X == 0 && ans[i].Y == 0)
			continue;
		if (s.find(make_pair(ans[i].X - 1, ans[i].Y)) == s.end() && s.find(make_pair(ans[i].X, ans[i].Y - 1)) == s.end())
		{
			cout << "NO" << endl;
			return 0;
		}
	}	
	cout << "YES" << endl;
	for (int i = 0; i < n; i++)
		cout << ans[i].X << " " << ans[i].Y << endl;
	return 0;
}