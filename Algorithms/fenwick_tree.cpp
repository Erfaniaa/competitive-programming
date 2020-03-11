#include <bits/stdc++.h>

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

//1-based BIT
template<class T = int>
struct BIT
{
    T* tree;
    int size;
    BIT()
    {

    }
    BIT(int _size)
    {
        size = _size;
        tree = new T[_size + 1];
		tree[0] = 0;
    }
    ~BIT()
    {
        delete[] tree;
    }
    void initialize(T *a, int length)
    {
		size = length;
		tree = new T[size + 1];
		for (int i = 0; i <= size; i++)
			tree[i] = 0;
		for (int i = 1; i <= length; i++)
			inc(i, a[i]);
    }
    T getSum(int i, int j)
    {
    	i = max(i, 1);
    	j = min(j, size);
    	return partialSum(j) - partialSum(i - 1);
    }
    void inc(int idx, int val)
    {
		for (; idx <= size; idx += (idx & (-idx)))
			tree[idx] += val;
    }
    T partialSum(int idx)
    {
		T ret = 0;
    	for (; idx >= 1; idx -= idx & (-idx))
			ret += tree[idx];
		return ret;
    }
};

int main()
{
	ios::sync_with_stdio(false);
	int a[1000];
	int n, q;
	cin >> n;
	debug(n);
	For (i, 1, n)
		cin >> a[i];
	BIT<int> b;
	b.initialize(a, n);
	cin >> q;
	debug(q);
	For (i, 1, q)
	{
		debug(i);
		char ch;
		cin >> ch;
		if (ch == 's')
		{
			int x, y;
			cin >> x >> y;
			cout << b.getSum(x, y) << endl;
		}
		else
		{
			int x, y;
			cin >> x >> y;
			b.inc(x, y);
		}
	}
	return 0;
}
