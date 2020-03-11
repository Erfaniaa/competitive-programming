/*
	SubmissionId	:	3974559
	ContestId	:	322
	Index	:	B
	ProblemName	:	Ciel and Flowers
	ProblemTags	:	['combinatorics', 'math']
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
    ll r, g, b, ans = 0;
    cin >> r >> g >> b;
    FOR (i, 0, 10000)
    {
        if (min(r, min(g, b)) < 0)
            break;
        if ((ll)i + (r / 3) + (g / 3) + (b / 3) > ans)
            ans = (ll)i + (r / 3) + (g / 3) + (b / 3);
        r--;
        g--;
        b--;
    }
    cout << ans << endl;
	return 0;
}
