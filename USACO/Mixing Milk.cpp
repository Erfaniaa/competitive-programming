/*
ID: erfan.a2
PROG: milk
LANG: C++
*/
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
#include <limits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <memory.h>
using namespace std;
typedef long long ll;
typedef map<int, int> mapi;
typedef map<char, int> mapc;
typedef map<string, int> maps;
typedef vector<int> veci;
typedef vector<double> vecd;
typedef vector<string> vecs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define cin fin
#define cout fout
ofstream fout("milk.out");
ifstream fin("milk.in");
#define un unsigned
#define pb push_back
#define mp make_pair
#define it iterator
#define val(x) #x << " = " << x << "   "
#define sqr(a) ((a) * (a))
#define sz(x) ((int) x.size())
#define clr(x, a) memset(x, a, sizeof x)
#define X first
#define Y second
#define TEST() cout << "Test!" << endl
#define pi 3.141592654
#define For(i, a, n) for(int i = a; i <= n; i++)
#define Ford(i, a, n) for(int i = a; i >= n; i--)
#define Fori(i, a, n) for(i = a; i <= n; i++)
#define Fordi(i, a, n) for(i = a; i >= n; i--)
#define all(n) n.begin(), n.end()
#define wln(x) cout << x << endl
#define w(x) cout << x
#define ri(n); int n; cin >> n;
#define rd(n); double n; cin >> n;
#define rl(n); ll n; cin >> n;
#define rc(c); char c; cin >> c;
#define rs(x); string x; getline(cin, x);
#define rarr(array, i, n); for(int i = 0; i <= n; i++) cin >> array[i];
#define warr(array, i, n); for(int i = 0; i <= n; i++) cout << array[i] << " ";
#define warrd(array, i, n); for(int i = n; i >= 0; i--) cout << array[i] << " ";
#define maxn 100010

struct Milk
{
    int a, b;
};

bool oper (Milk x, Milk y)
{
    return (x.a < y.a);
}

vector<Milk> f;

int main()
{
	ri(a);
	ri(n);
	int x, y;
	Milk g;
	For(i, 0, n - 1)
	{
        cin >> x >> y;
        g.a = x;
        g.b = y;
        f.pb(g);
	}
    sort(all(f), oper);
    int i = 0;
    ll sum = 0;
    while (1)
    {
        if (i >= n)
            break;
        if (f[i].b <= a)
        {
            a -= f[i].b;
            sum += f[i].a * f[i].b;
            i++;
        }
        else
        {
            sum += f[i].a * a;
            a = 0;
            break;
        }
        if (i >= n)
            break;
    }
    wln(sum);
	return 0;
}
