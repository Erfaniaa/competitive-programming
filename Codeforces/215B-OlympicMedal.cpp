/*
	SubmissionId	:	1983984
	ContestId	:	215
	Index	:	B
	ProblemName	:	Olympic Medal
	ProblemTags	:	['greedy', 'math']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
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
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef long long ll;
typedef map<int, int> mapi;
typedef map<char, int> mapc;
typedef map<string, int> maps;
typedef vector<int> veci;
typedef vector<double> vecd;
typedef vector<char> vecc;
typedef vector<string> vecs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define un unsigned
#define pb push_back
#define mp make_pair
#define IT iterator
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

int main()
{
	ios::sync_with_stdio(false);
	int r1 = 0, p1 = 0, p2 = 1000 * 1000;
	ri(n);
	For (i, 0, n - 1)
    {
        ri(a);
        r1 = max(a, r1);
    }
    cin >> n;
	For (i, 0, n - 1)
    {
        ri(a);
        p1 = max(a, p1);
    }
    cin >> n;
	For (i, 0, n - 1)
    {
        ri(a);
        p2 = min(a, p2);
    }

    rd(a);
    rd(b);
    double k = (b * p1) / (a * p2);
    double ans = sqrt(k * r1 * r1 / (k + 1));
    cout.precision(7);
    cout << fixed << ans << endl;
	return 0;
}
