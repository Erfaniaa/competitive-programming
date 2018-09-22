/*
	SubmissionId	:	4735484
	ContestId	:	353
	Index	:	B
	ProblemName	:	Two Heaps
	ProblemTags	:	['combinatorics', 'constructive algorithms', 'greedy', 'implementation', 'math', 'sortings']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<fstream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 10000

set<int> s[2];
int ans[500], n, sz[2], cnt[500], a[500];
int mark[500];
vector<int> nums1, nums2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, 2 * n)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	FOR (i, 1, 2 * n)
	{
		int v = a[i];
		if (mark[v] == 0 && cnt[v] >= 2)
		{
			s[0].insert(v);
			sz[0]++;
			ans[i] = 0;
			mark[v] = 1;
		}
		else
		{
			if (mark[v] == 1 && cnt[v] >= 2)
			{
				s[1].insert(v);
				sz[1]++;
				ans[i] = 1;
				mark[v] = 2;
			}
			else
			{
				if (cnt[v] == 1)
					nums1.pb(i);
				else
					nums2.pb(i);
			}
		}
	}
	FOR (j, 0, SZ(nums1) - 1)
	{
		int i = nums1[j];
		int v = a[i];
		int x = 1;
		if (SZ(s[0]) < SZ(s[1]))
			x = 0;
		if (sz[x] < n)
		{
			s[x].insert(v);
			sz[x]++;
			ans[i] = x;
		}
		else
		{
			s[1 - x].insert(v);
			sz[1 - x]++;
			ans[i] = 1 - x;
		}
	}
	FOR (j, 0, SZ(nums2) - 1)
	{
		int i = nums2[j];
		int v = a[i];
		if (sz[1] < n)
		{
			s[1].insert(v);
			sz[1]++;
			ans[i] = 1;
		}
		else
		{
			s[0].insert(v);
			sz[0]++;
			ans[i] = 0;
		}
	}
	cout << SZ(s[0]) * SZ(s[1]) << endl;
	FOR (i, 1, 2 * n)
		cout << ans[i] + 1 << " ";
	return 0;
}