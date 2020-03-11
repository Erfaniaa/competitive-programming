/*
	SubmissionId	:	2813351
	ContestId	:	259
	Index	:	B
	ProblemName	:	Little Elephant and Magic Square
	ProblemTags	:	['brute force', 'implementation']
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

vector<int> v, v2;
int a[4][4] = {0};

int sum(int row, int x)
{
	return a[row][1] + a[row][2] + a[row][3] + x;
}

bool comp(int r1, int r2)
{
	return sum(r1, 0) > sum(r2, 0);
}

int state;

int newPos(int x)
{
	if (state == 1)
		return x;
	else
		return 4 - x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	For (i, 1, 3)
		For (j, 1, 3)
			cin >> a[i][j];
	state = (int)(!a[1][1] && !a[2][2] && !a[3][3]);
	v.pb(1);
	v.pb(2);
	v.pb(3);
	sort(all(v), comp);
	v2.pb(0);
	For (i, 1, 2)
		For (j, 1, 3)
			if ((state && v[i] == j) || (state == 0 && 4 - v[i] == j))
			{
				a[v[i]][j] = sum(v[0], 0) - sum(v[i], 0) - 100000;
				v2.pb(a[v[i]][j]);
			}
	a[v[0]][newPos(v[0])] = -100000;
	For (x, 0, 1000 * 100 * 2)
		if (v2[0] + x > 0 && v2[1] + x > 0 && v2[2] + x > 0)
			if (sum(1, x) == sum(2, x) && sum(2, x) == sum(3, x) && sum(1, x) == a[1][newPos(1)] + a[2][newPos(2)] + a[3][newPos(3)] + 3 * x)
			{
				For (i, 1, 3)
				{
					For (j, 1, 3)
					{
						if ((state == 1 && i == j) || (state == 0 && 4 - i == j))
							cout << a[i][j] + x << " ";
						else
							cout << a[i][j] << " ";
					}
					cout << endl;
				}
				return 0;
			}
	return 0;
}
