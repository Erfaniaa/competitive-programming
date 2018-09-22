/*
	SubmissionId	:	3921352
	ContestId	:	16
	Index	:	A
	ProblemName	:	Flag
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
#define Size(x) ((int)((x).size()))
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)

int main()
{
    int xx, yy;
    cin >> yy >> xx;
    string s[1000];
    FOR (y, 1, yy)
        cin >> s[y];
    FOR (y, 1, yy)
    {
        char c = s[y][0];
        FOR (x, 0, Size(s[y]) - 1)
        {
            if (s[y][x] != c)
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    FOR (y, 1, yy - 1)
        if (s[y][0] == s[y + 1][0])
        {
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;
	return 0;
}
