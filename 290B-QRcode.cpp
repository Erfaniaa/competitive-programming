/*
	SubmissionId	:	3434558
	ContestId	:	290
	Index	:	B
	ProblemName	:	QR code
	ProblemTags	:	['*special', 'implementation']
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

string s[] = {
"111111101010101111100101001111111",
"100000100000000001010110001000001",
"101110100110110000011010001011101",
"101110101011001001111101001011101",
"101110101100011000111100101011101",
"100000101010101011010000101000001",
"111111101010101010101010101111111",
"000000001111101111100111100000000",
"100010111100100001011110111111001",
"110111001111111100100001000101100",
"011100111010000101000111010001010",
"011110000110001111110101100000011",
"111111111111111000111001001011000",
"111000010111010011010011010100100",
"101010100010110010110101010000010",
"101100000101010001111101000000000",
"000010100011001101000111101011010",
"101001001111101111000101010001110",
"101101111111000100100001110001000",
"000010011000100110000011010000010",
"001101101001101110010010011011000",
"011101011010001000111101010100110",
"111010100110011101001101000001110",
"110001010010101111000101111111000",
"001000111011100001010110111110000",
"000000001110010110100010100010110",
"111111101000101111000110101011010",
"100000100111010101111100100011011",
"101110101001010000101000111111000",
"101110100011010010010111111011010",
"101110100100011011110110101110000",
"100000100110011001111100111100000",
"111111101101000101001101110010001"
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y;
	cin >> x >> y;
	cout << s[x][y] << endl;
	return 0;
}
