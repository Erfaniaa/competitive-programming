/*
	SubmissionId	:	4000142
	ContestId	:	22
	Index	:	D
	ProblemName	:	Segments
	ProblemTags	:	['greedy', 'sortings']
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
vector<int> ans;
vector<pii> seg;
bool b[1001];

int main()
{
    cin >> n;
    FOR (i, 0, n - 1)
    {
        int a, b;
        cin >> a >> b;
        if (b > a)
            swap(a, b);
        seg.pb(mp(a, b));
    }
    sort(ALL(seg));
    FOR (i, 0, n - 1)
    {
        if (b[i])
            continue;
        int p = seg[i].X;
        ans.pb(p);
        FOR (j, 0, n - 1)
            if (p <= seg[j].X && p >= seg[j].Y)
                b[j] = true;
    }
    cout << SZ(ans) << endl;
    FOR (i, 0, SZ(ans) - 1)
        cout << ans[i] << " ";
	return 0;
}
