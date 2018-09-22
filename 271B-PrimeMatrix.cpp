/*
	SubmissionId	:	3103955
	ContestId	:	271
	Index	:	B
	ProblemName	:	Prime Matrix
	ProblemTags	:	['binary search', 'brute force', 'math', 'number theory']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <memory.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double dbl;
typedef float flt;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> void print(T a, int p = -1) { if (p >= 0) cout << fixed << setprecision(p); cout << a; }
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dx[] = {-1, 0, +1, 0};
const int dy[] = {0, +1, 0, -1};
const int inf = (int)1e9 + 5;
const ll linf = (ll)1e16 + 5;
const double eps = 1e-9;
const double pi = 3.141592654;
#define vec vector
#define un unsigned
#define pb push_back
#define mp make_pair
#define IT iterator
#define X first
#define Y second
#define debug(x) cerr << #x << " = " << x << " (line: " << __LINE__ << ")" << endl
#define sqr(a) ((a) * (a))
#define sz(x) ((int) x.size())
#define ms(x, a) memset(x, a, sizeof x)
#define test() cerr << "Test!" << " (line: " << __LINE__ << ")" << endl
#define For(i, a, b) for(typeof(b) i = (a); i <= (b); i++)
#define Ford(i, a, b) for(typeof(a) i = (a); i >= (b); i--)
#define Fit(i, v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define Fitd(i, v) for(typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); i--)
#define all(n) (n).begin(), (n).end()
#define wln(x) cout << x << endl
#define w(x) cout << x
#define r(x, type); type x; cin >> x;
#define rs(x); string x; cin.ignore(); getline(cin, x);
#define rarr(array, i, n); for(int i = 0; i <= n; i++) cin >> array[i];
#define warr(array, i, n); for(int i = 0; i <= n; i++) cout << array[i] << " ";
#define warrd(array, i, n); for(int i = n; i >= 0; i--) cout << array[i] << " ";
#define maxn 100010

bool prime[1000001];
int xx, yy;
int a[1000][1000];
int d[100001];
vector<int> primes;

int main()
{
	ios::sync_with_stdio(false);
	prime[1] = true;
	For (i, 2, 1000)
	{
	    if (!prime[i])
            For (j, 2, 1000000 / i)
                prime[j * i] = true;
	}
	For (i, 1, 200000)
        if (!prime[i])
            primes.pb(i);
    For (i, 0, 200000)
        d[i] = inf;
    For (i, 0, sz(primes) - 1)
        d[primes[i]] = 0;
    d[0] = 2;
    d[1] = 1;
    Ford (i, primes[sz(primes) - 1], 1)
        d[i] = min(d[i], d[i + 1] + 1);
    cin >> yy >> xx;
    For (y, 1, yy)
        For (x, 1, xx)
            cin >> a[x][y];
    ll ans = linf;
    For (y, 1, yy)
    {
        int temp = 0;
        For (x, 1, xx)
            temp += d[a[x][y]];
        if (temp < ans)
            ans = temp;
    }
    For (x, 1, xx)
    {
        int temp = 0;
        For (y, 1, yy)
            temp += d[a[x][y]];
        if (temp < ans)
            ans = temp;
    }
    cout << ans << endl;
	return 0;
}
