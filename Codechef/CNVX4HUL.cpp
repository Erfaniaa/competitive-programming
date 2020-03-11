#include <algorithm>
#include <iostream>
#include <vector>
#define x first
#define y second
using namespace std;
typedef pair<long long, long long> point;
const int MOD = 1000000007;
const int MAX = 410;
point p[MAX];
int p2[MAX], s[MAX][MAX], s1[MAX], s2[MAX];
long long ccw(point& a, point& b, point& c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
point o;
bool cmp(pair<point, pair<int, int> >& a, pair<point, pair<int, int> >& b)
{
	return (ccw(o, a.first, b.first) > 0);
}
void add(int &x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}
vector<pair<point, pair<int, int> > > le, ri;
void solve(point p, int *s)
{
	o = p;
	sort(le.begin(), le.end(), cmp);
	sort(ri.begin(), ri.end(), cmp);
	int ptr = 0,  sum = 0;
	for (int i = 0; i < ri.size(); i++)
	{
		while (ptr < le.size() && ccw(o, ri[i].first, le[ptr].first) > 0)
		{
			add(sum, le[ptr].second.first);
			ptr++;
		}
		s[ri[i].second.second] = sum;
	}
}
int in(point& a, point& b, point& c, point& d)
{
	if (ccw(a, b, d) > 0 &&
		ccw(b, c, d) > 0 &&
		ccw(c, a, d) > 0)
		return 1;
	if (ccw(a, b, d) < 0 &&
		ccw(b, c, d) < 0 &&
		ccw(c, a, d) < 0)
		return -1;
	return 0;
}
void div2(int &x)
{
	if (x % 2)
		x += MOD;
	x /= 2;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	p2[0] = 1;
	for (int i = 1; i < MAX; i++)
		p2[i] = p2[i - 1] * 2 % MOD;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				s[i][j] += in(p[0], p[i], p[j], p[k]);
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
			{
				le.clear();
				ri.clear();
				for (int k = 0; k < n; k++)
					if (k != i && k != j)
					{
						int cnt = s[i][j] + s[j][k] + s[k][i];
						cnt -= in(p[0], p[i], p[j], p[k]);
						cnt -= in(p[0], p[j], p[k], p[i]);
						cnt -= in(p[0], p[k], p[i], p[j]);
						cnt += in(p[i], p[j], p[k], p[0]);
						if (cnt < 0)
							cnt *= -1;
						if (ccw(p[i], p[j], p[k]) > 0)
							le.push_back(make_pair(p[k], make_pair(p2[cnt], k)));
						else
							ri.push_back(make_pair(p[k], make_pair(p2[cnt], k)));
					}
				solve(p[i], s1);
				solve(p[j], s2);
				for (int k = 0; k < ri.size(); k++)
				{
					int ind = ri[k].second.second;
					ans = (ans + 1LL * (s1[ind] - s2[ind] + MOD) * ri[k].second.first) % MOD;
				}
			}
	div2(ans);
	div2(ans);
	cout << ans << "\n";
	return 0;
}
