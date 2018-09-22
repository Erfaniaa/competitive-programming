/*
	SubmissionId	:	4666271
	ContestId	:	351
	Index	:	B
	ProblemName	:	Jeff and Furik
	ProblemTags	:	['combinatorics', 'dp', 'probabilities']
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
#define MAXN 3010

int n, a[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
		cin >> a[i];
	int inv = 0;
	FOR (i, 1, n)
		FOR (j, i + 1, n)
			if (a[i] > a[j])
				inv++;
	cout.precision(7);
	if (inv % 2 == 0)
		cout << fixed << (double)(2 * inv) << endl;
	else
		cout << fixed << (double)(2 * inv - 1) << endl;
	return 0;
}