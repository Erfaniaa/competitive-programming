/*
	SubmissionId	:	4353140
	ContestId	:	339
	Index	:	B
	ProblemName	:	Xenia and Ringroad
	ProblemTags	:	['implementation']
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
#include<list>
#include<queue>
#include<fstream>
#include<sstream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define MAXN 100010

int n, m, a, pos;
ll ans;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	pos = 1;
	FOR (i, 1, m)
	{
		cin >> a;
		int x = a - pos;
		if (x < 0)
			x += n;
		pos = a;
		ans += x;
	}
	cout << ans << endl;
	return 0;
}
