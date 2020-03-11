/*
	SubmissionId	:	4922446
	ContestId	:	149
	Index	:	E
	ProblemName	:	Martian Strings
	ProblemTags	:	['string suffix structures', 'strings']
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
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

string s, s2, t;
int k, f[MAXN], m;
int preMark[MAXN], sufMark[MAXN];

vector<int> kmp(string s, string t)
{
	f[0] = f[1] = 0;
	int k = 0;
	vector<int> d;
	FOR (i, 1, SZ(t) - 1)
	{
		while (k > 0 && t[k] != t[i])
			k = f[k];
		if (t[k] == t[i])
			k++;
		f[i + 1] = k;
	}
	k = 0;
	FOR (i, 0, SZ(s) - 1)
	{
		while (k > 0 && t[k] != s[i])
			k = f[k];
		if (t[k] == s[i])
			k++;
		if (k == SZ(t))
			k = f[k];
		d.pb(k);
	}
	return d;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	cin >> m;
	s2 = s;
	reverse(ALL(s2));
	int cnt = 0;
	vector<int> pre, suf;
	FOR (mm, 1, m)
	{
		cin >> t;
		string r = t;
		reverse(ALL(r));
		memset(preMark, -1, sizeof preMark);
		memset(sufMark, -1, sizeof sufMark);
		pre = kmp(s, t);
		suf = kmp(s2, r);
		reverse(ALL(suf));
		FOR (i, 0, SZ(pre) - 1)
		{
			int v = pre[i];
			if (preMark[v] == -1)
				preMark[v] = i;
		}
		FOR (i, 0, SZ(suf) - 1)
		{
			int v = suf[i];
			sufMark[v] = i;
		}
		bool flag = false;
		FOR (i, 1, SZ(t) - 1)
		{
			int j = SZ(t) - i;
			if (preMark[i] != -1 && sufMark[j] != -1 && sufMark[j] > preMark[i])
			{
				flag = true;
				break;
			}
		}
		if (flag)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}