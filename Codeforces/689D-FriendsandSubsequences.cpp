/*
	SubmissionId	:	18937376
	ContestId	:	689
	Index	:	D
	ProblemName	:	Friends and Subsequences
	ProblemTags	:	['binary search', 'data structures']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

int n, mx[MAXN][30], mn[MAXN][30], a[MAXN], b[MAXN];
long long ans;

int getMin(int l, int r)
{
	int len = 1, p = 0;
	while (len * 2 <= r - l + 1)
	{
		len *= 2;
		p++;
	}
	return min(mn[r][p], mn[l + len - 1][p]);
}

int getMax(int l, int r)
{
	int len = 1, p = 0;
	while (len * 2 <= r - l + 1)
	{
		len *= 2;
		p++;
	}
	return max(mx[r][p], mx[l + len - 1][p]);	
}

int lastZero(int idx)
{
	int l = 0;
	int r = idx;
	int ans = -2;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (getMax(mid, idx) - getMin(mid, idx) < 0)
			r = mid - 1;
		else
		{
			ans = mid;
			l = mid + 1;
		}
	}
	if (ans != -2 && getMax(ans, idx) - getMin(ans, idx) == 0)
	{
		// cout << "getMax: " << getMax(ans, idx) << endl;
		return ans;
	}
	else
		return -2;
}

int firstZero(int idx)
{
	int l = 0;
	int r = idx;
	int ans = -2;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (getMax(mid, idx) - getMin(mid, idx) > 0)
		{
			l = mid + 1;
		}
		else
		{
			ans = mid;
			r = mid - 1;
		}
	}
	return ans - 1;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mx[i][0] = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		mn[i][0] = b[i];
	}
	for (int j = 1; j < 30; j++)
	{
		for (int i = 0; i < n; i++)
		{
			int st = i - (1 << j) + 1;
			if (st < 0 || st >= n)
				continue;
			mx[i][j] = max(mx[i - (1 << (j - 1))][j - 1], mx[i][j - 1]);
			mn[i][j] = min(mn[i - (1 << (j - 1))][j - 1], mn[i][j - 1]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		int idx1 = firstZero(i);
		int idx2 = lastZero(i);
		// cout << i << ": " << idx1 << " " << idx2 << endl;
		if (idx1 == -2 || idx2 == -2)
			continue;
		ans += abs(idx2 - idx1);
	}
	cout << ans << endl;
	return 0;
}