/*
	SubmissionId	:	4199157
	ContestId	:	27
	Index	:	C
	ProblemName	:	Unordered Subsequence
	ProblemTags	:	['constructive algorithms', 'greedy']
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

int n;
vector<int> a, a2, a3;
vector<int> v1, v2, v3, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	a.pb(0);
	FOR (i, 1, n)
	{
        int x;
        cin >> x;
        a.pb(x);
    }
    a2 = a;
    sort(ALL(a2));
    a3 = a2;
    reverse(ALL(a3));
    if (a == a2 || a == a3)
    {
        cout << 0 << "\n";
        return 0;
    }
    FOR (i, 1, n - 2)
    {
        v1.clear();
        v1.pb(a[i]);
        int k = -1, l;
        FOR (j, i + 1, n)
            if (a[j] != v1[0])
            {
                v1.pb(a[j]);
                k = j;
                break;
            }
        if (k == -1)
            break;
        FOR (j, k + 1, n)
            if (a[j] != v1[1])
            {
                v1.pb(a[j]);
                l = j;
                break;
            }
        if (SZ(v1) < 3)
            break;
        v2 = v1;
        sort(ALL(v2));
        v3 = v2;
        reverse(ALL(v3));
        if (v1 != v2 && v1 != v3)
        {
            cout << 3 << "\n";
            cout << i << " " << k << " " << l << "\n";
            return 0;
        }
        i = k - 1;
    }
    cout << 0 << "\n";
	return 0;
}
