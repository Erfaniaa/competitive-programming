/*
	SubmissionId	:	5600926
	ContestId	:	20
	Index	:	C
	ProblemName	:	Dijkstra?
	ProblemTags	:	['graphs', 'shortest paths']
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
#define MAX 100000000000000000

struct Vertex
{
    ll dis;
    int p;
} vertex[100001];

map <int, vector < pll > > neighbor;
//map <int, bool> mark;

struct compare
{
    bool operator () (ll a, ll b)
    {
        return (vertex[a].dis > vertex[b].dis);
    }
};

priority_queue <int, vector<int>, compare> g;

void print(int p)
{
    if (p > 0)
    {
        print(vertex[p].p);
        cout << p << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    //cout << n << " " << m << endl;
    ll a, b, w;
    For (i, 1, m)
    {
        cin >> a >> b >> w;
        neighbor[a].pb(mp(b, w));
        neighbor[b].pb(mp(a, w));
    }
    //wln("OK!");
    vertex[1].dis = 0;
    vertex[1].p = 0;
    g.push(1);
    For (i, 2, n)
    {
        vertex[i].dis = MAX;
        //vertex[i].p = 0;
        //g.push(i);
    }
    /*while (!g.empty())
    {
        cout << g.top().dis << endl;
        g.pop();
    }*/
    while (!g.empty())
    {
        ll num = g.top();
        ll dis = vertex[num].dis;
        //mark[num] = true;
        //cout << num << " " << dis << ": " << endl;
        //if (dis == 1000 * 1000 * 1000)
        //    break;
        //if (num == n)
        //    break;
        g.pop();
        ll l = sz(neighbor[num]);
        For (j, 0, l - 1)
        {
            //cout << j << " " << edge[num][j] << endl;
            pii k = neighbor[num][j];
            if (/*(!mark[j]) && */(dis + k.Y < vertex[k.X].dis))
            {
                vertex[k.X].dis = dis + k.Y;
                vertex[k.X].p = num;
                g.push(k.X);
            }
        }
    }
    if (vertex[n].dis == MAX)
        wln(-1);
    else
    {
        print(n);
    }
    return 0;
}