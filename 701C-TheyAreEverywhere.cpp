/*
	SubmissionId	:	19349620
	ContestId	:	701
	Index	:	C
	ProblemName	:	They Are Everywhere
	ProblemTags	:	['binary search', 'two pointers']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n;
string s;
set<char> types;

bool check(int len, int typesCnt)
{
	int cnt = 0;
	int m[256];
	memset(m, 0, sizeof m);
	for (int i = 0; i < len; i++)
	{
		if (m[s[i]] == 0)
			cnt++;
		m[s[i]]++;
	}
	if (cnt == typesCnt)
		return true;
	for (int i = 1; i + len <= n; i++)
	{
		int j = i + len - 1;
		if (s[j] != s[i - 1])
		{
			if (m[s[j]] == 0)
				cnt++;
			if (m[s[i - 1]] == 1)
				cnt--;
			m[s[j]]++;
			m[s[i - 1]]--;
		}
		if (cnt == typesCnt)
			return true;
	}
	return false;
}

int main()
{
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		types.insert(s[i]);
	int l = 1, r = n, ans = n;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid, types.size()))
		{
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}