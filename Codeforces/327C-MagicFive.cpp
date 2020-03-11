/*
	SubmissionId	:	4040059
	ContestId	:	327
	Index	:	C
	ProblemName	:	Magic Five
	ProblemTags	:	['combinatorics', 'math']
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
#define MOD 1000000007

string s;
int k;

ll power(int a, int b)
{
    if (b == 0)
        return 1;
    else
        if (b % 2 == 0)
        {
            ll c = power(a, b / 2);
            return (c * c) % MOD;
        }
        else
            return (a * power(a, b - 1)) % MOD;
}

ll inverseMOD(int a)
{
    return power(a, MOD - 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> s;
	cin >> k;
	ll sum = 0;
	int l = SZ(s);
	ll _2l = power(2, l);
	ll im = inverseMOD(_2l - 1);
	k--;
	FOR (i, 0, l - 1)
        if (s[i] == '0' || s[i] == '5')
        {
            ll x = (power(2, i) * (power(_2l, k + 1) - 1)) % MOD;
            x = (x * im) % MOD;
            sum += x;
            sum %= MOD;
        }
    cout << sum << endl;
	return 0;
}
