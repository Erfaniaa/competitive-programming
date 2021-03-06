/*
	SubmissionId	:	4198929
	ContestId	:	27
	Index	:	A
	ProblemName	:	Next Test
	ProblemTags	:	['implementation', 'sortings']
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
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int cnt[4000];
	FOR (i, 1, n)
	{
        int a;
        cin >> a;
        cnt[a]++;
    }
    FOR (i, 1, 4000)
        if (!cnt[i])
        {
            cout << i << '\n';
            return 0;
        }
	return 0;
}
