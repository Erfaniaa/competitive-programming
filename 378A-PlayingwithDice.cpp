/*
	SubmissionId	:	5552140
	ContestId	:	378
	Index	:	A
	ProblemName	:	Playing with Dice
	ProblemTags	:	['brute force']
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

int a, b, ans1, ans2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b;
	FOR (i, 1, 6)
	{
		if (abs(i - a) < abs(i - b))
			ans1++;
		else if (abs(i - a) > abs(i - b))
			ans2++;
	}	
	cout << ans1 << " " << 6 - ans1 - ans2 << " " << ans2 << endl;
	return 0;
}