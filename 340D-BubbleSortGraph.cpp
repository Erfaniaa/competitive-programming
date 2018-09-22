/*
	SubmissionId	:	4405862
	ContestId	:	340
	Index	:	D
	ProblemName	:	Bubble Sort Graph
	ProblemTags	:	['binary search', 'data structures', 'dp']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

//
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

int n;
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	FOR (i, 0, n - 1)
	{
		int a;
		cin >> a;
		vector<int>::iterator it = lower_bound(ALL(v), a);
		if (it == v.end())
			v.pb(a);
		else
			*it = a;
	}
	cout << SZ(v) << endl;
	return 0;
}
