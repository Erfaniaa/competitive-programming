/*
	SubmissionId	:	16808092
	ContestId	:	653
	Index	:	B
	ProblemName	:	Bear and Compressing
	ProblemTags	:	['brute force', 'dfs and similar', 'dp', 'strings']
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

int n, q, ans;
string s[40], t[40];

void check(string st)
{
	if (st == "a")
		ans++;
	if (st.length() <= 1)
		return;
	for (int i = 1; i <= q; i++)
		if (st[0] == s[i][0] && st[1] == s[i][1])
		{
			string st2 = t[i] + st.substr(2, st.length() - 2);
			check(st2);
			return;
		}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= q; i++)
		cin >> s[i] >> t[i];
	int cnt = 1;
	for (int i = 1; i <= n; i++)
		cnt *= 6;
	for (int mask = 0; mask < cnt; mask++)
	{
		int m = mask;
		string tmp = string(n, 'a');
		int idx = n - 1;
		while (m > 0)
		{
			tmp[idx] += m % 6;
			m /= 6;
			idx--;
		}
		check(tmp);
	}
	cout << ans << endl;
	return 0;
}