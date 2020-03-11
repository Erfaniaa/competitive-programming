/*
	SubmissionId	:	5711987
	ContestId	:	382
	Index	:	A
	ProblemName	:	Ksenia and Pan Scales
	ProblemTags	:	['greedy', 'implementation']
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

string v[2], s, s2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	int k = 0;
	FOR (i, 0, SZ(s) - 1)
	{
		if(s[i] == '|')
		{
			k++;
			continue;
		}
		v[k].pb(s[i]);
	}
	cin >> s2;
	if ((SZ(s) - 1 + SZ(s2)) % 2 != 0)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	int m = (SZ(s) - 1 + SZ(s2)) / 2;
	int idx = 0;
	while (idx <= SZ(s2) - 1 && SZ(v[0]) < m)
	{
		v[0].pb(s2[idx]);
		idx++;
	}
	while (idx <= SZ(s2) - 1 && SZ(v[1]) < m)
	{
		v[1].pb(s2[idx]);
		idx++;
	}
	if (SZ(v[0]) == m && SZ(v[1]) == m)
		cout << v[0] << "|" << v[1] << endl;
	else
		cout << "Impossible" << endl;
	return 0;
}