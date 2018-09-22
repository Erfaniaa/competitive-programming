/*
	SubmissionId	:	14449746
	ContestId	:	602
	Index	:	B
	ProblemName	:	Approximating a Constant Range
	ProblemTags	:	['dp', 'two pointers']
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

int n, a[MAXN], ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int p1 = 1;
	int p2 = 1;
	ans = 1;
	bool great = false, less = false;
	for (int i = 2; i <= n; i++)
	{
		if (abs(a[i] - a[i - 1]) == 1)
		{
			if ((great && a[i] > a[i - 1]) || (less && a[i] < a[i - 1]))
				p1 = p2;
			p2 = i;
			great = less = false;
			if (a[i] > a[i - 1])
				great = true;
			if (a[i] < a[i - 1])
				less = true;
		}
		ans = max(ans, i - p1 + 1);
	}
	cout << ans << endl;
	return 0;
}