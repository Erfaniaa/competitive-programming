/*
	SubmissionId	:	14315897
	ContestId	:	597
	Index	:	B
	ProblemName	:	Restaurant
	ProblemTags	:	['dp', 'greedy', 'sortings']
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
#define MAXN 500010

pii t[MAXN];
int n, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i].Y >> t[i].X;
	sort(t, t + n);
	for (int i = 0; i < n; i++)
		swap(t[i].X, t[i].Y);
	for (int i = 0; i < n; i++)
	{
		ans++;
		int temp = t[i].Y;
		i++;
		while (i < n && t[i].X <= temp)
			i++;
		i--;
	}
	cout << ans << endl;
	return 0;
}