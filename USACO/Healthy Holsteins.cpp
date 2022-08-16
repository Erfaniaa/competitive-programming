/*
ID: erfan.a2
PROG: holstein
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
template<class F, class T> T convert(F a, T &b, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; ss >> b; return b; }
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

//#define cin fin
//#define cout fout
ofstream fout("holstein.out");
ifstream fin("holstein.in");

template<class T>
struct Vector
{
	int len;
	T* a;
	Vector(int maxSize)
	{
		a = new T[maxSize];
		len = 0;
	}
	~Vector()
	{
		delete[] a;
	}
	int size()
	{
		return len;
	}
	void push_back(T x)
	{
		len++;
		a[len - 1] = x;
	}
	void pop_back()
	{
		if (len > 0)
			len--;
	}
	void clear()
	{
		len = 0;
	}
	bool empty()
	{
		return len == 0;
	}
	T operator [] (int i)
	{
		return a[i];
	}
	void operator = (Vector b)
	{
		len = b.len;
		for (int i = 0; i < len; i++)
			a[i] = b.a[i];
	}
};

int ans[10000], v[10000], szans, szv;

int n, m, a[100], b[100][100];
bool mark[16];

void solve(int x[])
{
	bool correct = true;
	For (i, 0, n - 1)
	{
		if (x[i] > 0)
		{
			correct = false;
			break;
		}
	}
	if (correct)
	{
		if (szv < szans)
		{
			szans = szv;
			For (i, 0, szv - 1)
				ans[i] = v[i];
		}
		return;
	}
	int y[25];
	For (i, 0, m - 1)
	{
		if (!mark[i])
		{
			mark[i] = true;
			szv++;
			v[szv - 1] = i + 1;
			For (j, 0, n - 1)
				y[j] = x[j] - b[i][j];
			solve(y);
			szv--;
			mark[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	For (i, 0, n - 1)
		cin >> a[i];
	cin >> m;
	For (i, 0, m - 1)
		For (j, 0, n - 1)
			cin >> b[i][j];
	szans = 100;
	For (i, 1, 100)
		ans[i - 1] = i;
	solve(a);
	cout << szans;
	For (i, 0, szans - 1)
		cout << " " << ans[i];
	cout << endl;
	return 0;
}
