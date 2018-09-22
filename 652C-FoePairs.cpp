/*
	SubmissionId	:	16938718
	ContestId	:	652
	Index	:	C
	ProblemName	:	Foe Pairs
	ProblemTags	:	['two pointers']
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
#define MAXN 300010

int n, m, idx[MAXN], cnt[MAXN];
long long ans;
vector<pair<int, int> > pairs;
set<int> st;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		idx[x] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		if (idx[x] > idx[y])
			swap(x, y);
		pairs.push_back(make_pair(idx[x], idx[y]));
		
	}
	sort(pairs.begin(), pairs.end());
	pairs.erase(unique(pairs.begin(), pairs.end()), pairs.end());
	sort(pairs.begin(), pairs.end());
	for (int i = 0; i < pairs.size(); i++)
	{
		cnt[pairs[i].second]++;
		st.insert(pairs[i].second);
	}
	int cur = 0;
	for (int i = 1; i <= n; i++)
	{
		while (cur < (int)pairs.size() && pairs[cur].first < i)
		{
			cnt[pairs[cur].second]--;
			if (cnt[pairs[cur].second] == 0)
				st.erase(pairs[cur].second);
			cur++;
		}
		int lastAns = ans;
		if (cur < (int)pairs.size() && pairs[cur].first >= i)
			ans = ans + (long long)(*(st.begin()) - i);
		else
			ans = ans + (long long)(n - i + 1);
		// cout << i << ": " << ans - lastAns << endl;
	}
	cout << ans << endl;
	return 0;
}