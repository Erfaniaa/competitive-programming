/*
	SubmissionId	:	3999740
	ContestId	:	22
	Index	:	C
	ProblemName	:	System Administrator
	ProblemTags	:	['graphs']
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

int n, m, v;
vector<int> comp1;
vector<int> comp2;
vector<pii> edges;
map<int, bool> mark[100011];

int main()
{
    cin >> n >> m >> v;
    if (m < n - 1)
    {
        cout << -1 << endl;
        return 0;
    }
    int halfN = 1;
    FOR (i, 1, n)
    {
        if (SZ(comp1) >= halfN)
            break;
        if (i != v)
        {
            comp1.pb(i);
            //cout << i << " ";
        }
    }
    int last = comp1[SZ(comp1) - 1];
    //cout << endl;
    comp1.pb(v);
    comp2.pb(v);
    FOR (i, last + 1, n)
        if (i != v)
        {
            comp2.pb(i);
            //cout << i << " ";
        }
    //cout << endl;
    sort(ALL(comp1));
    sort(ALL(comp2));
    FOR (i, 0, SZ(comp1) - 2)
    {
        edges.pb(mp(comp1[i], comp1[i + 1]));
        mark[comp1[i]][comp1[i + 1]] = true;
    }
    FOR (i, 0, SZ(comp2) - 2)
    {
        edges.pb(mp(comp2[i], comp2[i + 1]));
        mark[comp2[i]][comp2[i + 1]] = true;
    }
    FOR (i, 0, SZ(comp1) - 1)
        FOR (j, i + 1, SZ(comp1) - 1)
            if (!mark[comp1[i]][comp1[j]])
            {
                if (SZ(edges) >= m)
                    break;
                edges.pb(mp(comp1[i], comp1[j]));
                mark[comp1[i]][comp1[j]] = true;
            }
    FOR (i, 0, SZ(comp2) - 1)
        FOR (j, i + 1, SZ(comp2) - 1)
            if (!mark[comp2[i]][comp2[j]])
            {
                if (SZ(edges) >= m)
                    break;
                edges.pb(mp(comp2[i], comp2[j]));
                mark[comp2[i]][comp2[j]] = true;
            }
    if (m > SZ(edges))
    {
        cout << -1 << endl;
        return 0;
    }
    FOR (i, 0, SZ(edges) - 1)
        cout << edges[i].X << " " << edges[i].Y << endl;
	return 0;
}
