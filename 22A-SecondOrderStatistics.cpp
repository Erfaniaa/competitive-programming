/*
	SubmissionId	:	3999420
	ContestId	:	22
	Index	:	A
	ProblemName	:	Second Order Statistics
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

int n;
int a[1000];

int main()
{
    cin >> n;
    FOR (i, 0, n - 1)
        cin >> a[i];
    sort(a, a + n);
    if (a[0] == a[n - 1])
        cout << "NO" << endl;
    else
    {
        unique(a, a + n);
        cout << a[1] << endl;
    }
	return 0;
}
