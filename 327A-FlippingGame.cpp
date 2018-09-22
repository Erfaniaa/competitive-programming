/*
	SubmissionId	:	4040068
	ContestId	:	327
	Index	:	A
	ProblemName	:	Flipping Game
	ProblemTags	:	['brute force', 'dp', 'implementation']
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

int a[1000];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int sum = 0;
    int ans = -10000;
    FOR (i, 1, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    FOR (i, 1, n)
        FOR (j, i, n)
        {
            int sum2 = 0;
            FOR (k, i, j)
                if (a[k])
                    sum2--;
                else
                    sum2++;
            ans = max(sum2, ans);
        }
    cout << ans + sum << endl;
	return 0;
}
