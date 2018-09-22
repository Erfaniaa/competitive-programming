/*
	SubmissionId	:	6878876
	ContestId	:	436
	Index	:	A
	ProblemName	:	Feed with Candy
	ProblemTags	:	['greedy']
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
#define MAXN 100010

int n, x, t, jump, ans1, ans2;
vector<pair<int, int> > s[2];
bool mark[2][2010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
	{
		int type, h, m;
		cin >> type >> h >> m;
		s[type].push_back(make_pair(h, m));
	}
	jump = x;
	t = 0;
	for (int k = 1; k <= n; k++)
	{
		int m = -1, idx = -1;
		for (int i = 0; i < SZ(s[t]); i++)
			if (!mark[t][i] && s[t][i].first <= jump && s[t][i].second > m)
			{
				idx = i;
				m = s[t][i].second;
			}
		if (idx != -1)
		{
			jump += m;
			mark[t][idx] = true;
			t = 1 - t;
			ans1++;
		}
		else
			break;
	}
	jump = x;
	t = 1;
	memset(mark, 0, sizeof mark);
	for (int k = 1; k <= n; k++)
	{
		int m = -1, idx = -1;
		for (int i = 0; i < SZ(s[t]); i++)
			if (!mark[t][i] && s[t][i].first <= jump && s[t][i].second > m)
			{
				idx = i;
				m = s[t][i].second;
			}
		if (idx != -1)
		{
			jump += m;
			mark[t][idx] = true;
			t = 1 - t;
			ans2++;
		}
		else
			break;
	}
	cout << max(ans1, ans2) << endl;
	return 0;
}