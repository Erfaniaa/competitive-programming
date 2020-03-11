/*
	SubmissionId	:	3946792
	ContestId	:	320
	Index	:	A
	ProblemName	:	Magic Numbers
	ProblemTags	:	['brute force', 'greedy']
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
#define Size(x) ((int)((x).size()))
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)

vector<string> q;
string s;

int main()
{
    cin >> s;
    q.pb("1");
    q.pb("14");
    q.pb("144");
    FOR (i, 0, Size(q) - 1)
    {
        string a, b, c;
        a = q[i] + q[0];
        b = q[i] + q[1];
        c = q[i] + q[2];
        if (Size(a) <= 10)
            q.pb(a);
        if (Size(b) <= 10)
            q.pb(b);
        if (Size(c) <= 10)
            q.pb(c);
    }
    bool ans = false;
    FOR (i, 0, Size(q) - 1)
        if (q[i] == s)
            ans = true;
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
	return 0;
}
