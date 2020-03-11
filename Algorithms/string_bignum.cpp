#include <bits/stdc++.h>

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
#define debug(x) cerr << #x << " = " << x << " (line: " << __LINE__ << ")" << endl
#define sqr(a) ((a) * (a))
#define sz(x) ((int)(x).size())
#define first(x) (*((x).begin()))
#define last(x) (*((x).end() - 1))
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

struct BigNum
{
    string d;
    bool positive;
    BigNum()
    {
    	positive = true;
    	d.clear();
    	d.pb(0);
    }
    void normalize()
    {
        For (i, 0, sz(d) - 2)
        {
            d[i + 1] += d[i] / 10;
            d[i] = d[i] % 10;
        }
        while (1)
        {
            int x = sz(d) - 1;
            if (d[x] > 9)
            {
                d.pb(d[x] / 10);
                d[x] = d[x] % 10;
            }
            else
                break;
        }
        while (sz(d) >= 1 && d[sz(d) - 1] == 0)
            d.resize(sz(d) - 1);
    }
    void get(int a)
    {
        d.clear();
        positive = (a >= 0);
        if (a < 0)
			a = -a;
        if (a == 0)
        {
            d.pb(0);
            return;
        }
        while (a > 0)
        {
            d.pb(a % 10);
            a /= 10;
        }
    }
    void get(ll a)
    {
        d.clear();
        positive = (a >= 0);
        if (a < 0)
			a = -a;
        if (a == 0)
        {
            d.pb(0);
            return;
        }
        while (a > 0)
        {
            d.pb(a % 10);
            a /= 10;
        }
    }
    void get(string s)
    {
    	d.clear();
    	int l = sz(s);
    	d.resize(l);
    	For (i, 0, l - 1)
			d[i] = s[l - 1 - i] - 48;
		normalize();
    }
    void add(BigNum a)
    {
        d.resize(max(sz(d), sz(a.d)));
        a.d.resize(max(sz(d), sz(a.d)));
        int l = max(sz(d) - 1, sz(a.d) - 1);
        For (i, 0, l)
            d[i] = d[i] + a.d[i];
        normalize();
    }
    void sub(BigNum a)
    {
        d.resize(max(sz(d), sz(a.d)));
        a.d.resize(max(sz(d), sz(a.d)));
        int l = max(sz(d) - 1, sz(a.d) - 1);
        For (i, 0, l)
        {
            if (d[i] < a.d[i])
            {
                d[i] += 10;
                d[i + 1]--;
            }
            d[i] = d[i] - a.d[i];
        }
        normalize();
    }
    void mul(BigNum a)
    {
        BigNum c;
        For (i, 0, sz(a.d) - 1)
        {
            BigNum b;
            b.d.resize(i);
            For (j, 0, sz(d) - 1)
                b.d.pb(a.d[i] * d[j]);
            c.add(b);
        }
        d = c.d;
    }
    void div(BigNum b)
    {
        BigNum a, a2, s, co, ans;
        BigNum _1, _10;
        _1.get(1);
        _10.get(10);
        a.d = d;
        if (a < b)
        {
            *this = 0;
            return;
        }
        while (!(a < b))
        {
            a2.d.clear();
            a2.d.pb(a.d[sz(a.d) - 1]);
            int j = sz(a.d) - 1;
            while (a2 < b && j > 0)
            {
                j--;
                a2.d.insert(a2.d.begin(), a.d[j]);
            }
            co.get(0);
            while (!(a2 < (co + _1) * b))
                co = co + _1;
            s = co * b;
            ans.d.insert(ans.d.begin(), co.d[0]);
            For (i, 1, sz(a.d) - sz(a2.d))
                s = s * _10;
            a = a - s;
        }
        while (!(*this < ans * b * _10))
            ans = ans * _10;
		ans.normalize();
		*this = ans;
    }
    BigNum div2()
    {
    	BigNum _5, ans;
    	_5.get(5);
    	ans = _5 * *this;
    	if (sz(d) > 1)
			ans.d.erase(ans.d.begin());
		else
			ans.get(0);
    	return ans;
    }
    BigNum mod(BigNum b)
    {
        BigNum a, a2, s, co, ans;
        BigNum _1, _10;
        _1.get(1);
        _10.get(10);
        a.d = d;
        if (a < b)
            return a;
        while (!(a < b))
        {
            a2.d.clear();
            a2.d.pb(a.d[sz(a.d) - 1]);
            int j = sz(a.d) - 1;
            while (a2 < b && j > 0)
            {
                j--;
                a2.d.insert(a2.d.begin(), a.d[j]);
            }
            co.get(0);
            while (!(a2 < (co + _1) * b))
                co = co + _1;
            s = co * b;
            ans.d.insert(ans.d.begin(), co.d[0]);
            For (i, 1, sz(a.d) - sz(a2.d))
                s = s * _10;
            a = a - s;
        }
        if (sz(a.d) == 0)
            a.get(0);
        return a;
    }
    ll mod(ll a)
    {
        ll ans = 0;
        Ford (i, sz(d) - 1, 0)
            ans = ((10 * ans) + d[i]) % a;
        return ans;
    }
    void print()
    {
    	if (!positive)
			cout << '-';
        Ford (i, sz(d) - 1, 0)
            cout << (int)d[i];
    }
    void println()
    {
    	print();
		cout << '\n';
    }
    int operator [] (int i)
    {
        return (int)d[i];
    }
    BigNum operator + (BigNum a)
    {
        BigNum b;
        b.d = d;
        if (positive == a.positive)
        {
			b.add(a);
			b.positive = positive;
        }
        else if (!a.positive)
        	b.sub(a);
		else
			a.sub(b);
        return b;
    }
    BigNum operator - (BigNum a)
    {
        BigNum b;
        b.d = d;
        if (*this == a)
        {
        	BigNum ans;
        	ans.get(0);
			return ans;
        }
        if (a <= b)
        {
			b.sub(a);
			b.positive = true;
			return b;
        }
        else
        {
			a.sub(b);
			a.positive = false;
			return a;
        }
    }
    BigNum operator * (BigNum a)
    {
        BigNum b;
        b.d = d;
        b.mul(a);
        b.positive = positive && a.positive;
        return b;
    }
    BigNum operator / (BigNum a)
    {
        BigNum b;
        b.d = d;
        b.div(a);
        b.positive = positive && a.positive;
        return b;
    }
    BigNum operator % (BigNum a)
    {
        BigNum b;
        b.d = d;
        b.mod(a);
        b.positive = positive && a.positive;
        return b;
    }
    BigNum operator - ()
    {
    	BigNum b = *this;
    	b.positive = !b.positive;
    	return b;
    }
    bool operator < (BigNum a)
    {
    	if (!positive && a.positive)
			return true;
		if (positive && !a.positive)
			return false;
    	if (!positive && !a.positive)
    	{
			if (sz(a.d) > sz(d))
				return false;
			if (sz(a.d) < sz(d))
				return true;
			if (sz(a.d) == sz(d))
			{
				int l = sz(d);
				Ford (i, l - 1, 0)
				{
					if (a.d[i] < d[i])
						return true;
					if (a.d[i] > d[i])
						return false;
				}
				return false;
			}
    	}
    	if (positive && a.positive)
    	{
			if (sz(a.d) < sz(d))
				return false;
			if (sz(a.d) > sz(d))
				return true;
			if (sz(a.d) == sz(d))
			{
				int l = sz(d);
				Ford (i, l - 1, 0)
				{
					if (a.d[i] > d[i])
						return true;
					if (a.d[i] < d[i])
						return false;
				}
				return false;
			}
    	}
    }
    BigNum abs()
    {
    	BigNum ans = *this;
    	ans.positive = true;
    	return ans;
    }
    bool operator > (BigNum a)
    {
        return (a < *this);
    }
    bool operator == (BigNum a)
    {
        return (d == a.d && positive == a.positive);
    }
    bool operator <= (BigNum a)
    {
    	return (*this < a || *this == a);
    }
    bool operator >= (BigNum a)
    {
    	return (*this > a || *this == a);
    }
    BigNum operator = (BigNum a)
    {
        d = a.d;
        positive = a.positive;
        return a;
    }
    BigNum operator = (string a)
    {
    	positive = (a[0] != '-');
    	if (a[0] == '-' || a[0] == '+')
			a.erase(0, 1);
        get(a);
        return *this;
    }
    BigNum operator = (int a)
    {
    	positive = (a >= 0);
        get(a);
        return *this;
    }
    BigNum operator = (ll a)
    {
    	positive = (a >= 0);
        get(a);
        return *this;
    }
    BigNum operator += (BigNum a)
    {
    	*this = *this + a;
    	return *this;
    }
    BigNum operator -= (BigNum a)
    {
    	*this = *this - a;
    	return *this;
    }
    BigNum operator *= (BigNum a)
    {
    	*this = *this * a;
    	return *this;
    }
    BigNum operator /= (BigNum a)
    {
    	*this = *this / a;
    	return *this;
    }
    BigNum operator %= (BigNum a)
    {
    	*this = *this % a;
    	return *this;
    }
    BigNum operator ++ ()
    {
    	BigNum _1;
    	_1 = 1;
    	*this += _1;
    	return *this;
    }
    BigNum operator -- ()
    {
    	BigNum _1;
    	_1 = 1;
    	*this -= _1;
    	return *this;
    }
};

int main()
{
	string a, b;
    cin >> a >> b;
    BigNum x, y;
    x = a;
    y = b;
    (x * y).println();
    (x + y).println();
    (x - y).println();
    (x / y).println();
    ++x;
    x.println();
	return 0;
}
