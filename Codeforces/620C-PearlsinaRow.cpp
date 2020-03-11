/*
	SubmissionId	:	18370862
	ContestId	:	620
	Index	:	C
	ProblemName	:	Pearls in a Row
	ProblemTags	:	['greedy']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[300010];
map<int, int> cnt;
vector<pair<int, int> > ans;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int last = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt[a[i]]++;
		if (cnt[a[i]] >= 2)
		{
			ans.push_back(make_pair(last + 1, i));
			last = i;
			cnt.clear();
		}
	}
	if (last != n && ans.size())
	{
		int l = ans[ans.size() - 1].first;
		ans.pop_back();
		ans.push_back(make_pair(l, n));
	}
	if (ans.size())
	{
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i].first << " " << ans[i].second << endl;
	}
	else
		cout << -1 << endl;
	return 0;
}