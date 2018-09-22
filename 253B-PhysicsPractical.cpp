/*
	SubmissionId	:	2730660
	ContestId	:	253
	Index	:	B
	ProblemName	:	Physics Practical
	ProblemTags	:	['binary search', 'dp', 'two pointers']
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

#define cin fin
#define cout fout
ofstream fout("output.txt");
ifstream fin("input.txt");

vector<int> v;
int n, cnt[10001], pos[10001], pos2[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	For (i, 0, n - 1)
	{
		int a;
		cin >> a;
		cnt[a]++;
		v.pb(a);
	}
	sort(all(v));
	For (i, 0, sz(v) - 2)
		if (v[i] != v[i + 1])
			pos[v[i]] = i;
	pos[v[sz(v) - 1]] = sz(v) - 1;
	Ford (i, sz(v) - 1, 1)
		if (v[i] != v[i - 1])
			pos2[v[i]] = i;
	pos2[v[0]] = 0;
	v.erase(unique(all(v)), v.end());
	int ans = n - 1;
	For (i, 0, sz(v) - 1)
		Ford (j, sz(v) - 1, i + 1)
			if (v[i] * 2 >= v[j])
			{
				int x1, x2;
				if (i == 0)
					x1 = 0;
				else
					x1 = pos[v[i - 1]] + 1;
				if (j == sz(v) - 1)
					x2 = 0;
				else
					x2 = n - pos2[v[j + 1]];
				ans = min(ans, x1 + x2);
				break;
			}
	cout << ans << endl;
	return 0;
}
