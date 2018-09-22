/*
	SubmissionId	:	4191925
	ContestId	:	334
	Index	:	B
	ProblemName	:	Eight Point Sets
	ProblemTags	:	['sortings']
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
#define INF 100000000

pii p[10];
int minX = INF, minY = INF;
map<int, int> b[1000001];
vector<int> pX, pY[10];

int main()
{
	ios::sync_with_stdio(false);
	FOR (i, 0, 7)
	{
        cin >> p[i].X >> p[i].Y;
        minX = min(minX, p[i].X);
        minY = min(minY, p[i].Y);
    }
    FOR (i, 0, 7)
    {
        p[i].X -= minX;
        p[i].Y -= minY;
        if (b[p[i].X][p[i].Y])
        {
            cout << "ugly" << endl;
            return 0;
        }
        b[p[i].X][p[i].Y] = 1;
    }
    FOR (i, 0, 7)
        if (p[i].Y == 0)
            pX.pb(p[i].X);
    if (SZ(pX) != 3 || b[0][0] == 0)
    {
        cout << "ugly" << endl;
        return 0;
    }
    sort(ALL(pX));
    FOR (i, 0, 2)
        FOR (j, 0, 7)
            if (p[j].X == pX[i])
                pY[i].pb(p[j].Y);
    FOR (i, 0, 2)
        sort(ALL(pY[i]));
    if (SZ(pY[0]) != 3 || SZ(pY[1]) != 2 || SZ(pY[2]) != 3)
    {
        cout << "ugly" << endl;
        return 0;
    }
    if (pY[0][2] == pY[1][1] && pY[0] == pY[2])
        cout << "respectable" << endl;
    else
        cout << "ugly" << endl;
	return 0;
}
