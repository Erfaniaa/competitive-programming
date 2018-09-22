/*
	SubmissionId	:	6564308
	ContestId	:	280
	Index	:	B
	ProblemName	:	Maximum Xor Secondary
	ProblemTags	:	['data structures', 'implementation', 'two pointers']
	ProgrammingLanguage	:	GNU C++0x
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

long long n, a[MAXN], ans = 0;
vector<int> st;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		while (SZ(st) > 0 && st[SZ(st) - 1] < a[i])
		{
			ans = max(ans, a[i] ^ st[SZ(st) - 1]);
			st.pop_back();
		}
		if (SZ(st) > 0)
			ans = max(ans, a[i] ^ st[SZ(st) - 1]);
		st.push_back(a[i]);
	}
	cout << ans << endl;
	return 0;
}