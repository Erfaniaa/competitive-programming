/*
	SubmissionId	:	4574031
	ContestId	:	344
	Index	:	B
	ProblemName	:	Simple Molecules
	ProblemTags	:	['brute force', 'math']
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
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 10000

int d1, d2, d3;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> d1 >> d2 >> d3;
	FOR (x, 0, d1)
	{
		int y = d1 - x;
		int k1 = d2 - x;
		int k2 = d3 - y;
		if (k1 == k2 && k1 >= 0)
		{
			cout << x << " " << k1 << " " << y << endl;
			return 0;
		}
	}
	cout << "Impossible" << endl;
	return 0;
}