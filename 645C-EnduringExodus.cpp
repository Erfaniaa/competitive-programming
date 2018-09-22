/*
	SubmissionId	:	16790411
	ContestId	:	645
	Index	:	C
	ProblemName	:	Enduring Exodus
	ProblemTags	:	['binary search', 'two pointers']
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

int a[MAXN], sum[MAXN], n, k;

bool check(int t)
{
	for (int i = 1; i <= n; i++)
		if (a[i] == 1)
			if (sum[min(i + t, n)] - sum[max(i - t - 1, 0)] >= k + 1)
				return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		char ch;
		cin >> ch;
		a[i] = (ch == '0');
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 0, r = n, ans = n;
	while (r >= l)
	{
		int mid = (l + r) / 2;
		if (check(mid))
		{
			r = mid - 1;
			ans = min(ans, mid);
		}
		else
			l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}