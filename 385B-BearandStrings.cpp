/*
	SubmissionId	:	5791517
	ContestId	:	385
	Index	:	B
	ProblemName	:	Bear and Strings
	ProblemTags	:	['brute force', 'greedy', 'implementation', 'math', 'strings']
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
#define MAXN 10010

int ans;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	int last = -2;
	FOR (i, 0, SZ(s) - 1)
	{
		bool tmp = (i + 3 <= SZ(s) - 1 && s[i] == 'b' && s[i + 1] == 'e' && s[i + 2] == 'a' && s[i + 3] == 'r');
		if (tmp)
		{
			ans += (i - last - 1) * (SZ(s) - (i + 3));
			last = i - 1;
		}
	}
	cout << ans << endl;
	return 0;
}