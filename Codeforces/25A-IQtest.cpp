/*
	SubmissionId	:	4076136
	ContestId	:	25
	Index	:	A
	ProblemName	:	IQ test
	ProblemTags	:	['brute force']
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

int c[2], idx[2], n;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	FOR (i, 1, n)
	{
        int a;
        cin >> a;
        c[a % 2]++;
        idx[a % 2] = i;
    }
    if (c[0] == 1)
        cout << idx[0] << endl;
    else
        cout << idx[1] << endl;
	return 0;
}
