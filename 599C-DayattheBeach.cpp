/*
	SubmissionId	:	14422288
	ContestId	:	599
	Index	:	C
	ProblemName	:	Day at the Beach
	ProblemTags	:	['sortings']
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

int a[MAXN], mn[MAXN], mx[MAXN], n, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	mx[0] = -1;
	mn[n + 1] = 1000000010;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		mx[i] = max(mx[i - 1], a[i]);
	for (int i = n; i >= 1; i--)
		mn[i] = min(mn[i + 1], a[i]);
	for (int i = 1; i <= n; i++)
		if (mx[i] <= mn[i + 1])
			ans++;
	cout << ans << endl;
	return 0;
}