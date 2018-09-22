/*
	SubmissionId	:	28234269
	ContestId	:	822
	Index	:	C
	ProblemName	:	Hacker, pack your bags!
	ProblemTags	:	['binary search', 'greedy', 'implementation', 'sortings']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int n, sum, ans = 2000000010;
vector<pair<int, int> > bucket[MAXN];
vector<int> mn[MAXN];
vector<pair<pair<int, int>, int> > a;

int main()
{
	cin >> n >> sum;
	for (int i = 0; i < n; i++)
	{
		int l, r, cost;
		cin >> l >> r >> cost;
		a.push_back(make_pair(make_pair(l, r), cost));
		bucket[r - l + 1].push_back(make_pair(l, cost));
	}
	for (int i = 0; i < MAXN; i++)
	{
		if (bucket[i].size() == 0)
			continue;
		sort(bucket[i].begin(), bucket[i].end());
		mn[i].resize(bucket[i].size());
		mn[i][(int)mn[i].size() - 1] = bucket[i][(int)bucket[i].size() - 1].second;
		for (int j = (int)bucket[i].size() - 2; j >= 0; j--)
			mn[i][j] = min(mn[i][j + 1], bucket[i][j].second);
	}
	for (int i = 0; i < n; i++)
	{
		int bucketIdx = sum - (a[i].first.second - a[i].first.first + 1);
		if (bucketIdx < 0 || bucketIdx > MAXN)
			continue;
		if (bucket[bucketIdx].size() == 0)
			continue;
		int idx = lower_bound(bucket[bucketIdx].begin(), bucket[bucketIdx].end(), make_pair(a[i].first.second + 1, -1)) - bucket[bucketIdx].begin();
		if (idx < bucket[bucketIdx].size())
			ans = min(ans, a[i].second + mn[bucketIdx][idx]);
	}
	if (ans == 2000000010)
		ans = -1;
	cout << ans << endl;
	return 0;
}