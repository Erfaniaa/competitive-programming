/*
	SubmissionId	:	14064541
	ContestId	:	593
	Index	:	A
	ProblemName	:	2Char
	ProblemTags	:	['brute force']
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
#define MAXN 10000

inline bool isValid(string &s, char ch1, char ch2)
{
	for (int i = 0; i < SZ(s); i++)
		if (s[i] != ch1 && s[i] != ch2)
			return false;
	return true;
}

string s[110];
int n, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	for (char c1 = 'a'; c1 <= 'z'; c1++)
		for (char c2 = 'a'; c2 <= 'z'; c2++)
		{
			int tmp = 0;
			for (int i = 1; i <= n; i++)
				if (isValid(s[i], c1, c2))
					tmp += SZ(s[i]);
			ans = max(ans, tmp);
		}
	cout << ans << endl;
	return 0;
}