/*
	SubmissionId	:	3921370
	ContestId	:	16
	Index	:	B
	ProblemName	:	Burglar and Matches
	ProblemTags	:	['greedy', 'implementation', 'sortings']
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
#define Size(x) ((int)((x).size()))
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)

pii a[10000];

int main()
{
    int n, m;
    cin >> n >> m;
    FOR (i, 0, m - 1)
        cin >> a[i].Y >> a[i].X;
    sort(a, a + m);
    ll ans = 0;
    FORD (i, m - 1, 0)
    {
        int k = min(a[i].Y, n);
        n -= k;
        ans += (ll)k * a[i].X;
    }
    cout << ans << endl;
	return 0;
}
