/*
	SubmissionId	:	13695689
	ContestId	:	216
	Index	:	D
	ProblemName	:	Spider's Web
	ProblemTags	:	['binary search', 'sortings', 'two pointers']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010
#define SZ(x) ((int)(x).size())

int n, ans;
vector<int> a[MAXN];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int x;
			cin >> x;
			a[i].push_back(x);
		}
		sort(a[i].begin(), a[i].end());
	}
	for (int i = 0; i < n; i++)
	{
		int l = (i + n - 1) % n, r = (i + 1) % n;
		int cntL[100010] = {0}, cntR[100010] = {0};
		int k = 0;
		for (int j = 0; j < SZ(a[i]); j++)
			while (k < SZ(a[l]) && a[l][k] < a[i][j])
				k++, cntL[j]++;
		k = 0;
		for (int j = 0; j < SZ(a[i]); j++)
			while (k < SZ(a[r]) && a[r][k] < a[i][j])
				k++, cntR[j]++;
		for (int j = 1; j < SZ(a[i]); j++)
		{
			//if (cntL[j] != cntR[j])
			//	cout << "(" << i << ", " << j << "): " << "(" << cntL[j] << ", " << cntR[j] << ")" << endl;
			ans += (cntL[j] != cntR[j]);
		}
	}
	cout << ans << endl;
	return 0;
}