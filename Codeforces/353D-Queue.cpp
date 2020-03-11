/*
	SubmissionId	:	4744973
	ContestId	:	353
	Index	:	D
	ProblemName	:	Queue
	ProblemTags	:	['constructive algorithms']
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
#define mp make_pair
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 1000010

int idx, f[MAXN];
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	FOR (i, 0, SZ(s) - 1)
		if (s[i] == 'F')
		{
			idx++;
			if (idx != i + 1)
				f[idx] = max(f[idx - 1] + 1, i + 1 - idx);
		}
	cout << f[idx] << endl;
	return 0;
}