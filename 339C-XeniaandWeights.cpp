/*
	SubmissionId	:	4353309
	ContestId	:	339
	Index	:	C
	ProblemName	:	Xenia and Weights
	ProblemTags	:	['constructive algorithms', 'dfs and similar', 'dp', 'graphs', 'greedy', 'shortest paths']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

//Be name Khoda
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<fstream>
#include<sstream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define MAXN 100010

int m;
bool w[11];
vector<int> ans;

void dfs(int s1, int s2, int last, bool isLeft)
{
	if (SZ(ans) == m)
	{
		cout << "YES" << endl;
		FOR (i, 0, SZ(ans) - 1)
			cout << ans[i] << " ";
		exit(0);
	}
	FOR (i, 1, 10)
		if (w[i] && i != last)
		{
			ans.pb(i);
			if (isLeft && s1 + i > s2)
				dfs(s1 + i, s2, i, 1 - isLeft);
			if (!isLeft && s1 < s2 + i)
				dfs(s1, s2 + i, i, 1 - isLeft);
			ans.pop_back();
		}

}

int main()
{
	ios::sync_with_stdio(false);
	FOR (i, 1, 10)
	{
		char c;
		cin >> c;
		if (c == '1')
			w[i] = 1;
	}
	cin >> m;
	dfs(0, 0, -1, true);
	cout << "NO" << endl;
	return 0;
}
