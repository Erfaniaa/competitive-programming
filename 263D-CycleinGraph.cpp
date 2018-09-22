/*
	SubmissionId	:	2945292
	ContestId	:	263
	Index	:	D
	ProblemName	:	Cycle in Graph
	ProblemTags	:	['dfs and similar', 'graphs']
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

vector<int> path[2];
vector<int> ans;
vector<int> adj[100001];
bool neighbor[100001];
bool mark[100001];
int father[100001];
int n, k, m, lastNode = 1, cnt;

void dfs(int v);
void findPath(int v)
{
    path[cnt - 1].pb(v);
    if (v == 1)
        return;
    findPath(father[v]);
}

void solve(int v, int cnt)
{
    findPath(v);
    For (i, 1, n)
        father[i] = 0;
    if (cnt == 2)
    {
        int idx;
        For (i, 0, sz(path[0]) - 1)
            ans.pb(path[0][i]);
        Ford (i, sz(path[1]) - 2, 0)
            ans.pb(path[1][i]);
        For (i, 0, sz(adj[v]) - 1)
            neighbor[adj[v][i]] = true;
        For (i, 1, n)
           adj[i].clear();
        path[0].clear();
        path[1].clear();
        For (i, 0, sz(ans) - 1)
        {
            if (neighbor[ans[i]])
            {
                idx = i;
                break;
            }
        }
        cout << sz(ans) - idx << endl;
        Ford (i, sz(ans) - 1, idx)
            cout << ans[i] << " ";
        cout << endl;
        ans.clear();
        exit(0);
    }
    else
        dfs(1);
}

void dfs(int v)
{
    bool flag = false;
    mark[v] = true;
    For (i, 0, sz(adj[v]) - 1)
        if (!mark[adj[v][i]])
        {
            //mark[adj[v][i]] = true;
            flag = true;
            father[adj[v][i]] = v;
            //lastNode = adj[v][i];
            dfs(adj[v][i]);
        }
    if (!flag)
    {
        cnt++;
        solve(v, cnt);
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    For (i, 1, m)
    {
        int v, u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(1);
    return 0;
}
