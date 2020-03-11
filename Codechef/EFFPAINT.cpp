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

struct Map
{
    int size;
    char s[60][60];
    bool operator == (Map &b)
    {
        For (y, 0, size - 1)
            For (x, 0, size - 1)
                if (s[y][x] != b.s[y][x])
                    return false;
        return true;
    }
} m1, m2;

vector<pii> a, b;

double countDif(int &x1, int &y1, int &x2, int &y2)
{
    int ret = 0;
    For (x, x1, x2)
        For (y, y1, y2)
            if (m1.s[y][x] != m2.s[y][x])
                ret++;
            else
                ret--;
    return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	m1.size = m2.size = n;
	int cnt = 0;
	For (y, 0, n - 1)
        For (x, 0, n - 1)
        {
            cin >> m2.s[y][x];
            if (m2.s[y][x] == 'B')
                cnt++;
            m1.s[y][x] = 'W';
        }
    int ans = 0;
    int xx1, xx2, yy1, yy2;
    double mx;
    while (cnt > 0)
    {
        mx = -1;
        /*For (y1, 0, n - 1)
            For (x1, 0, n - 1)
                For (y2, y1, n - 1)
                    For (x2, x1, n - 1)*/
                    For (j, 1, n * n * n * n)
                    {
                        int x1 = rand() % n;
                        int y1 = rand() % n;
                        int x2, y2;
                        do
                        {
                            x2 = rand() % n;
                            y2 = rand() % n;
                        } while (x2 < x1 || y2 < y1);
                        double temp = countDif(x1, y1, x2, y2);
                        //if (temp > 0)
                        if (temp > mx && temp > 0)
                        {
                            mx = temp;
                            xx1 = x1;
                            xx2 = x2;
                            yy1 = y1;
                            yy2 = y2;
                            break;
                        }
                    }
        cnt -= mx;
        ans++;
        a.pb(mp(xx1, yy1));
        b.pb(mp(xx2, yy2));
        For (x, xx1, xx2)
            For (y, yy1, yy2)
            {
                char ch;
                if (m1.s[y][x] == 'W')
                    ch = 'B';
                else
                    ch = 'W';
                m1.s[y][x] = ch;
            }
        //cout << debug(mx) << endl;
        //cout << xx1 + 1 << " " << yy1 + 1 << endl;
        /*For (y, 0, n - 1)
        {
            For (x, 0, n - 1)
                cout << m1.s[y][x];
            cout << endl;
        }
        cin.get();
        cin.get();*/
    }
    cout << ans << endl;
    For (i, 0, ans - 1)
    {
        cout << a[i].Y << " " << a[i].X << " " << b[i].Y << " " << b[i].X << " F" << endl;
    }
	return 0;
}
