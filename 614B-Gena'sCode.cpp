/*
	SubmissionId	:	15352162
	ContestId	:	614
	Index	:	B
	ProblemName	:	Gena's Code
	ProblemTags	:	['implementation']
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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, cnt = 0;
	cin >> n;
	string t = "1";
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		if (s == "0")
		{
			cout << 0 << endl;
			return 0;
		}
		bool flag = s[0] == '1';
		if (flag)
		{
			for (int i = 1; i < (int)s.length(); i++)
				if (s[i] != '0')
				{
					flag = false;
					break;
				}
		}
		if (flag)
			cnt += (int)s.length() - 1;
		else
			t = s;
	}
	cout << t << string(cnt, '0') << endl;
	return 0;
}