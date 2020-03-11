/*
	SubmissionId	:	5506405
	ContestId	:	376
	Index	:	C
	ProblemName	:	Divisible by Seven
	ProblemTags	:	['math', 'number theory']
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

int d[] = {1, 6, 8, 9}, m, cnt[300], ans2;
string s, ans1;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	FOR (i, 0, SZ(s) - 1)
		cnt[s[i]]++;
	cnt['1']--;
	cnt['6']--;
	cnt['8']--;
	cnt['9']--;
	FOR (i, '1', '9')
		FOR (j, 1, cnt[i])
		{
			cout << i;
			m = ((m * 10) + (int)(i - '0')) % 7;
		}
	do
	{
		if ((10000 * m + 1000 * d[0] + 100 * d[1] + 10 * d[2] + d[3]) % 7 == 0)
		{
			cout << 1000 * d[0] + 100 * d[1] + 10 * d[2] + d[3];
			break;
		}
	} while (next_permutation(d, d + 4));
	FOR (i, 1, cnt['0'])
		cout << 0;
	cout << "\n";
	return 0;
}