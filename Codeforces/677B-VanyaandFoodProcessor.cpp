/*
	SubmissionId	:	18191934
	ContestId	:	677
	Index	:	B
	ProblemName	:	Vanya and Food Processor
	ProblemTags	:	['implementation', 'math']
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

int n;
int h, k, empty;
long long ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> h >> k;
	empty = h;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x <= empty)
			empty -= x;
		else
		{
			ans++;
			empty = h;
			empty -= x;
		}
		ans += (h - empty) / k;
		empty = h - ((h - empty) % k);
	}
	if (empty < h)
		ans++;
	cout << ans << endl;
	return 0;
}