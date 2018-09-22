/*
	SubmissionId	:	4191787
	ContestId	:	334
	Index	:	A
	ProblemName	:	Candy Bags
	ProblemTags	:	['implementation']
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

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	FOR (i, 1, n)
	{
        FOR (j, (i - 1) * (n / 2) + 1, i * (n / 2))
            cout << j << " ";
        FOR (j, (i - 1) * (n / 2) + 1, i * (n / 2))
            cout << n * n - j + 1 << " ";
        cout << endl;
	}
	return 0;
}
