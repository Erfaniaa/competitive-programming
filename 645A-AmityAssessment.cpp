/*
	SubmissionId	:	16786519
	ContestId	:	645
	Index	:	A
	ProblemName	:	Amity Assessment
	ProblemTags	:	['brute force', 'constructive algorithms', 'implementation']
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
	string s = "0000";
	string t = s;
	map<string, bool> m;
	m.clear();
	cin >> s[0] >> s[1] >> s[3] >> s[2];
	m[s] = true;
	for (int i = 1; i <= 24; i++)
		for (int j = 0; j < 4; j++)
			if (s[j] == 'X')
			{
				swap(s[j], s[(j + 3) % 4]);
				m[s] = true;
				break;
			}
	cin >> t[0] >> t[1] >> t[3] >> t[2];
	if (m[t])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}