/*
ID: erfan.a2
PROG: range
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
ofstream fout("range.out");
ifstream fin("range.in");

char a[251][251];
int sumx[251][251], sumy[251][251], n;
int d[251][251];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	For (y, 1, n)
		For (x, 1, n)
		{
			cin >> a[x][y];
			a[x][y] = ((int)a[x][y] - 48 + 1) % 2;
		}
	For (x, 1, n)
		For (y, 1, n)
			sumy[x][y] = sumy[x][y - 1] + (int)a[x][y];
	For (y, 1, n)
		For (x, 1, n)
			sumx[x][y] = sumx[x - 1][y] + (int)a[x][y];
	For (x, 1, n)
		For (y, 1, n)
			d[x][y] = (a[x][y] + 1) % 2;
	For (x, 1, n)
		For (y, 1, n)
		{
			int l = d[x - 1][y - 1];
			if (sumx[x][y] - sumx[x - l - 1][y] == 0 && sumy[x][y] - sumy[x][y - l - 1] == 0)
					d[x][y] = max(d[x][y], d[x - 1][y - 1] + 1);
			Ford (k, l, 1)
				if (sumx[x][y] - sumx[x - k - 1][y] == 0 && sumy[x][y] - sumy[x][y - k - 1] == 0)
				{
					d[x][y] = max(d[x][y], k + 1);
					break;
				}
		}
	For (k, 2, n)
	{
		int ans = 0;
		For (x, 1, n)
			For (y, 1, n)
				if (d[x][y] >= k)
					ans++;
		if (ans)
			cout << k << " " << ans << endl;
		else
			break;
	}
	return 0;
}
