/*
	SubmissionId	:	4794594
	ContestId	:	356
	Index	:	A
	ProblemName	:	Knight Tournament
	ProblemTags	:	['data structures', 'dsu']
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
#define MAXN 300010

set<int> p;
int ans[MAXN], n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	FOR (i, 1, n)
		p.insert(i);
	FOR (i, 1, m)
	{
		int l, r, x;
		cin >> l >> r >> x;
		set<int>::iterator a = p.lower_bound(l);
		set<int>::iterator b = p.upper_bound(r);
		for (set<int>::iterator i = a; i != b; i++)
		{
			int v = *i;
			if (v != x)
				ans[v] = x;
		}
		p.erase(a, b);
		p.insert(x);
	}
	FOR (i, 1, n)
		cout << ans[i] << " ";
	return 0;
}