/*
	SubmissionId	:	3921481
	ContestId	:	16
	Index	:	C
	ProblemName	:	Monitor
	ProblemTags	:	['binary search', 'number theory']
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

ll a, b, x, y;

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

int bs(ll l, ll r)
{
    if (r == l + 1)
    {
        if (r * x <= a && r * y <= b)
            return r;
        else
            if (l * x <= a && l * y <= b)
                return l;
    }
    if (l == r)
        return l;
    ll m = (l + r) / 2;
    ll x2 = m * x;
    ll y2 = m * y;
    if (x2 > a || y2 > b)
        return bs(l, m);
    else
        return bs(m, r);
}

int main()
{
    cin >> a >> b >> x >> y;
    int g = gcd(x, y);
    x /= g;
    y /= g;
    int k = bs(0, 2000 * 1000 * 1000);
    cout << k * x << " " << k * y << endl;
	return 0;
}
