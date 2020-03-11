#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 21

int n, m;
vector<int> v[MAXN];
bool mat[MAXN][MAXN], mark[20010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	FOR (i, 0, m - 1)
	{
		int cnt;
		cin >> cnt;
		FOR (j, 1, cnt)
		{
			int x;
			cin >> x;
			v[i].pb(x);
		}
	}
	/*FOR (i, 0, m - 1)
		FOR (j, i + 1, m - 1)
		{
			memset(mark, 0, sizeof mark);
			FOR (k, 0, SZ(v[i]) - 1)
				mark[v[i][k]] = true;
			bool flag = true;
			FOR (k, 0, SZ(v[j]) - 1)
				if (mark[v[j][k]])
				{
					flag = false;
					break;
				}
			mat[i][j] = mat[j][i] = flag;
		}*/
	FOR (i, 0, m - 1)
		FOR (j, i + 1, m - 1)
		{
			int p = 0;
			bool flag = true;
			FOR (k, 0, SZ(v[i]) - 1)
			{
				if (v[i][k] == v[j][p])
					flag = false;
				while (v[j][p] < v[i][k] && p + 1 <= SZ(v[j]) - 1)
					p++;
			}
			mat[i][j] = mat[j][i] = flag;
		}
	/*FOR (i, 0, m - 1)
	{
		FOR (j, 0, m - 1)
			cout << mat[i][j] << " ";
		cout << endl;
	}*/
	int maxMask = 1 << m;
	vector<int> tmp;
	int ans = 0;
	FOR (mask, 0, maxMask - 1)
	{
		tmp.clear();
		FOR (j, 0, m - 1)
			if (mask & (1 << j))
				tmp.pb(j);
		bool flag = true;
		FOR (i, 0, SZ(tmp) - 1)
			FOR (j, i + 1, SZ(tmp) - 1)
				if (!mat[tmp[i]][tmp[j]])
				{
					flag = false;
					break;
				}
		if (flag)
			ans = max(ans, __builtin_popcount(mask));
	}
	cout << ans << endl;
	return 0;
}