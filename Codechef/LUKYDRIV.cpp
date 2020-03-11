#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <list>
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
template<class F, class T> T convert(F a, T &b, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; ss >> b; return b; }
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
#define maxn 1000000007

int co[100 * 1000 + 2][10], co2[10];

int digits(int n)
{
    return ((int)(log10(n)) + 1);
}

void getCount(int j, string s)
{
    ms(co[j], 0);
    For (i, 0, sz(s) - 1)
        co[j][s[i] - 48]++;
}

void getCount2(string s)
{
    ms(co2, 0);
    For (i, 0, sz(s) - 1)
        co2[s[i] - 48]++;
}

ll hash(int i)
{
    ll ans = 0;
    For (j, 0, 9)
        ans = 10 * ans + co[i][j];
    return ans;
}

ll combine(ll n, ll r)
{
    if (r > n)
        return 0;
    if (r == 0)
        return 1;
    if (r == 1)
        return n % maxn;
    if (r == 2)
        return (n * (n - 1) / 2) % maxn;
    if (r == 3)
        return (n * (n - 1) * (n - 2) / 6) % maxn;
    if (r == 4)
        return (n * (n - 1) * (n - 2) * (n - 3) / 24) % maxn;
}

map<ll, bool> m;

int main()
{
	ios::sync_with_stdio(false);
	r(t, int);
	int l = 0;
	vec<string> v;
	For (a, 1, 10 * 1000 - 1)
    {
        if (a % 9 == 0)
        {
            string x, x2;
            x2 = convert(a, x);
            //wln(x);
            For (i, 0, 4 - sz(x2))
            {
                //v.pb(x);
                getCount(/*sz(v) - 1*/l, x);
                l++;
                //wln(x);
                //warr(co[sz(v) - 1], j, 9);
                //wln("");
                x = "0" + x;
            }
        }
    }
    string s;
	For (i, 0, t - 1)
	{
	    cin >> s;
	    getCount2(s);
	    ll sum = 0;
	    m.clear();
	    For (j, 0, l - 1)
            if (!m[hash(j)])
            {
                m[hash(j)] = true;
                ll sum2 = 1;
                For (k, 0, 9)
                    if (co[j][k] > 0)
                        sum2 = (sum2 * combine(co2[k], co[j][k])) % maxn;
                /*if (sum2)
                {
                    wln("v: " << v[j]);
                    wln("sum2: " << sum2);
                    wln("hash: " << hash(j));
                    cin.get();
                }*/
                sum = (sum + sum2) % maxn;
            }
	    wln(sum);
	}
	return 0;
}
