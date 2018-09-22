/*
	SubmissionId	:	3999465
	ContestId	:	22
	Index	:	B
	ProblemName	:	Bargaining Table
	ProblemTags	:	['brute force', 'dp']
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

int xx, yy;
char c[100][100];

int main()
{
    cin >> yy >> xx;
    FOR (y, 1, yy)
        FOR (x, 1, xx)
            cin >> c[x][y];
    int ans = 0;
    FOR (x1, 1, xx)
        FOR (y1, 1, yy)
            FOR (x2, x1, xx)
                FOR (y2, y1, yy)
                {
                    bool isEmpty = true;
                    FOR (x, x1, x2)
                        if (isEmpty)
                            FOR (y, y1, y2)
                                if (c[x][y] == '1')
                                {
                                    isEmpty = false;
                                    break;
                                }
                    if (isEmpty)
                        ans = max(ans, 2 * (x2 - x1 + y2 - y1 + 2));
                }
    cout << ans << endl;
	return 0;
}
