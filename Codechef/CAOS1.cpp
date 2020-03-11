#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<fstream>
#include<sstream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define MAXN 110

int dx[] = {0, -1, -2, +1, +2,  0,  0,  0,  0};
int dy[] = {0,  0,  0,  0,  0, -1, -2, +1, +2};
int t;
char c[MAXN][MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	FOR (tt, 1, t)
	{
		int ans = 0, xx, yy;
		cin >> yy >> xx;
		FOR (y, 1, yy)
			FOR (x, 1, xx)
				cin >> c[x][y];
		FOR (y, 3, yy - 2)
			FOR (x, 3, xx - 2)
			{
				bool correct = true;
				FOR (k, 0, 8)
				{
					int x2 = x + dx[k];
					int y2 = y + dy[k];
					if (c[x2][y2] != '^')
					{
						correct = false;
						break;
					}
				}
				if (correct)
					ans++;
			}
		cout << ans << endl;
	}
	return 0;
}
