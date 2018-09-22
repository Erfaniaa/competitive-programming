/*
	SubmissionId	:	17044597
	ContestId	:	659
	Index	:	B
	ProblemName	:	Qualifying Contest
	ProblemTags	:	['sortings']
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

vector<pair<int, string> > region[10010];
int n, m, cnt[10010][810];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string s;
		int r, sc;
		cin >> s >> r >> sc;
		region[r].push_back(make_pair(sc, s));
		cnt[r][sc]++;
	}
	for (int i = 1; i <= m; i++)
	{
		sort(region[i].begin(), region[i].end());
		reverse(region[i].begin(), region[i].end());
		region[i].erase(unique(region[i].begin(), region[i].end()), region[i].end());
		int mx1 = region[i][0].first;
		int mx2 = region[i][1].first;
		bool flag;
		if (cnt[i][mx1] == 1)
		{
			if (cnt[i][mx2] == 1)
				flag = true;
			else
				flag = false;
		}
		else
		{
			if (cnt[i][mx1] == 2)
				flag = true;
			else
				flag = false;
		}
		if (flag)
			cout << region[i][0].second << " " << region[i][1].second << endl;
		else
			cout << "?" << endl;
	}
	return 0;
}