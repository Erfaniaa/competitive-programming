/*
	SubmissionId	:	15993395
	ContestId	:	626
	Index	:	B
	ProblemName	:	Cards
	ProblemTags	:	['constructive algorithms', 'dp', 'math']
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

bool mark[210][210][210];

void bt(int r, int g, int b)
{
	if (r < 0 || g < 0 || b < 0)
		return;
	if (mark[r][g][b])
		return;
	mark[r][g][b] = true;
	if (r >= 2)
		bt(r - 1, g, b);
	if (g >= 2)
		bt(r, g - 1, b);
	if (b >= 2)
		bt(r, g, b - 1);
	if (g >= 1 && b >= 1)
		bt(r + 1, g - 1, b - 1);
	if (r >= 1 && b >= 1)
		bt(r - 1, g + 1, b - 1);
	if (r >= 1 && g >= 1)
		bt(r - 1, g - 1, b + 1);
}

string s;
int r, g, b, n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cin >> s;
	for (int i = 0; i < (int)s.length(); i++)
	{
		if (s[i] == 'R')
			r++;
		if (s[i] == 'G')
			g++;
		if (s[i] == 'B')
			b++;
	}
	bt(r, g, b);
	if (mark[0][0][1])
		cout << 'B';
	if (mark[0][1][0])
		cout << 'G';
	if (mark[1][0][0])
		cout << 'R';
	return 0;
}