/*
	SubmissionId	:	15991374
	ContestId	:	626
	Index	:	A
	ProblemName	:	Robot Sequence
	ProblemTags	:	['brute force', 'implementation']
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

int x, y;

void change(char ch)
{
	if (ch == 'U')
		y++;
	if (ch == 'D')
		y--;
	if (ch == 'R')
		x++;
	if (ch == 'L')
		x--;
}

string s;
int ans, n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cin >> s;
	for (int i = 0; i < (int)s.length(); i++)
	{
		x = y = 0;
		for (int j = i; j < (int)s.length(); j++)
		{
			change(s[j]);
			if (x == 0 && y == 0)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}