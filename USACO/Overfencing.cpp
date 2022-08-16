/*
ID: erfan.a2
PROG: maze1
LANG: C++
*/
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
typedef unsigned long long ull;
typedef long double ld;
typedef double dbl;
typedef float flt;
typedef string str;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T b; ss >> b; return b; }
template<class T> void print(T a, int p = -1) { if (p >= 0) cout << fixed << setprecision(p); cout << a; }
template<class T> bool isPrime(T a) { if (a == 1) return false; T n = (T)sqrt(a); for (T i = 2; i <= n; i++) if (a % i == 0) return false; return true; }
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
#define debug(x) cerr << #x << " = " << x << " #" << __LINE__ << '\n'
#define sqr(a) ((a) * (a))
#define sz(x) ((int)(x).size())
#define first(x) (*((x).begin()))
#define last(x) (*((x).end() - 1))
#define ms(x, a) memset(x, a, sizeof x)
#define test() cerr << "Test!" << " #" << __LINE__ << '\n'
#define For(i, a, b) for(typeof(b) i = (a); i <= (b); i++)
#define Ford(i, a, b) for(typeof(a) i = (a); i >= (b); i--)
#define Fit(i, v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define Fitd(i, v) for(typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); i--)
#define all(n) (n).begin(), (n).end()
#define wln(x) cout << x << '\n'
#define w(x) cout << x
#define r(x, type); type x; cin >> x;
#define rs(x); string x; getline(cin, x);
#define rarr(array, i, a, n); for(int i = a; i <= n; i++) cin >> array[i];
#define warr(array, i, a, n); for(int i = a; i <= n; i++) cout << array[i] << " ";
#define warrd(array, i, a, n); for(int i = n; i >= a; i--) cout << array[i] << " ";
#define maxn 100010

#define cin fin
#define cout fout
ofstream fout("maze1.out");
ifstream fin("maze1.in");

int w, h;
string s[1000];
bool mark[1001][1001];

struct Node
{
    int x, y, d;
    Node(int _x = 0, int _y = 0, int _d = 0)
    {
        x = _x;
        y = _y;
        d = _d;
    }
};

vec<Node> p, q, exits;

int main()
{
	ios::sync_with_stdio(false);
	cin >> w >> h;
	cin.ignore();
	For (y, 0, 2 * h)
        getline(cin, s[y]);
    bool flag = false;
    For (y, 0, 2 * h)
        For (x, 0, 2 * w)
            if (s[y][x] == ' ' && (x == 0 || y == 0 || x == (2 * w) || y == (2 * h)))
                exits.pb(Node(x, y, 0));
    For (i, 0, 1)
    {
        if (exits[i].x == 0)
            exits[i].x--;
        if (exits[i].y == 0)
            exits[i].y--;
        if (exits[i].x == 2 * w)
            exits[i].x++;
        if (exits[i].y == 2 * h)
            exits[i].y++;
    }
    p.pb(exits[0]);
    p.pb(exits[1]);
    int ans = -1;
    For (i, 0, sz(p) - 1)
    {
    	ans = max(ans, p[i].d);
        For (j, 0, 3)
        {
            int x2 = p[i].x + 2 * dx[j];
            int y2 = p[i].y + 2 * dy[j];
            int x1 = p[i].x + dx[j];
            int y1 = p[i].y + dy[j];
            int d2 = p[i].d + 1;
            if (x2 >= 0 && x2 <= (2 * w) && y2 >= 0 && y2 <= (2 * h) && !mark[x2][y2] && s[y1][x1] == ' ' && s[y2][x2] == ' ')
            {
                mark[x2][y2] = true;
                p.pb(Node(x2,  y2, d2));
            }
        }
    }
    cout << ans << endl;
	return 0;
}
