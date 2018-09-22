/*
	SubmissionId	:	2084003
	ContestId	:	221
	Index	:	B
	ProblemName	:	Little Elephant and Numbers
	ProblemTags	:	['implementation']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
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
typedef long double ld;
typedef double dbl;
typedef float flt;
typedef string str;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T b; ss >> b; return b; }
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

bool b[10];

void digits(int x)
{
	while (x > 0)
	{
		b[x % 10] = true;
		x /= 10;
	}
}

bool commonDigit(int x)
{
	while (x > 0)
	{
		if (b[x % 10])
			return true;
		x /= 10;
	}
	return false;
}

int ans;
vec<pair<int, int> > v;

void tajzie(int x)
{
	int s;
	if (x % 2 == 0)
		s = x / 2;
	else
		s = x / 3;
	bool f = false;
	For (i, 2, s)
	{
		if (x % i == 0)
		{
			v.pb(mp(i, 0));
			while (x % i == 0)
			{
				v[sz(v) - 1].Y++;
				x /= i;
				f = true;
			}
			if (x == 1 || i > x)
				break;
		}
	}
	if (!f)
		v.pb(mp(x, 1));
}

void solve(int num, int l)
{
	if (l > sz(v) - 1)
	{
		//debug(num);
		if (commonDigit(num))
		{
			//debug(num);
			ans++;
		}
	}
	else
	{
		solve(num, l + 1);
		For (i, 1, v[l].Y)
		{
			num *= v[l].X;
			solve(num, l + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	//int n = 999000011;
	r(n, int);
	if (n == 1)
		wln(1);
	else
	{
		digits(n);
		tajzie(n);
		//For (i, 0, sz(v) - 1)
		//	cout << v[i].X << " " << v[i].Y << endl;
		solve(1, 0);
		wln(ans);
	}
	return 0;
}
