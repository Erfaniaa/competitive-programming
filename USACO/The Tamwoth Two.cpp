/*
ID: erfan.a2
PROG: ttwo
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
typedef map<int, int> imap;
typedef map<char, int> cmap;
typedef map<string, int> smap;
typedef vector<int> ivec;
typedef vector<double> dvec;
typedef vector<string> svec;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define cout fout
#define cin fin
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
ofstream fout("ttwo.out");
ifstream fin("ttwo.in");

struct Object
{
    int x, y, d;
} F, C;

int fl[10][10][10001];
int dx[4] = {0, +1, 0, -1};
int dy[4] = {-1, 0, +1, 0};

int main()
{
    string s[10];
    Fori(y, 0, 9)
        Fori(x, 0, 9)
        {
            rc(c);
            if (c == 'C')
            {
                C.x = x;
                C.y = y;
                C.d = 0;
                c = '.';
            }
            else
            if (c == 'F')
            {
                F.x = x;
                F.y = y;
                F.d = 0;
                c = '.';
            }
            s[y] += c;
        }
    Fori(i, 0, 10000)
    {
        fl[C.y][C.x][i] = true;
        if (C.y + dy[C.d] >= 10 || C.y + dy[C.d] < 0 || C.x + dx[C.d] >= 10 || C.x + dx[C.d] < 0)
        {
            C.d = (C.d + 1) % 4;
            continue;
        }
        else
            if (s[C.y + dy[C.d]][C.x + dx[C.d]] == '*')
            {
                C.d = (C.d + 1) % 4;
                continue;
            }
        C.x += dx[C.d];
        C.y += dy[C.d];
    }
    Fori(i, 0, 10000)
    {
        if (fl[F.y][F.x][i])
        {
            cout << i << endl;
            //cout.close();
            return 0;
        }
        if (F.y + dy[F.d] >= 10 || F.y + dy[F.d] < 0 || F.x + dx[F.d] >= 10 || F.x + dx[F.d] < 0)
        {
            F.d = (F.d + 1) % 4;
            continue;
        }
        else
            if (s[F.y + dy[F.d]][F.x + dx[F.d]] == '*')
            {
                F.d = (F.d + 1) % 4;
                continue;
            }
        F.x += dx[F.d];
        F.y += dy[F.d];
    }
    cout << 0 << endl;
    return 0;
}
