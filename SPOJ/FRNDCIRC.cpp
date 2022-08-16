#include <iostream>
#include <unordered_map>

using namespace std;

#define MAXN 200010

string s1, s2;
int cnt, par[MAXN], namesCount, t, sz[MAXN], n;
unordered_map<string, int> m;

inline int find(int x)
{
	if (par[x] != x)
		return par[x] = find(par[x]);
	return x;
}

inline int Union(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return sz[x];
	if (sz[x] > sz[y])
		swap(x, y);
	par[x] = y;
	sz[y] += sz[x];
	sz[x] = sz[y];
	return sz[x];
}

inline int getHash(string &s)
{
	if (m.count(s) == 0)
		return m[s] = ++namesCount;
	return m[s];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i <= 2 * n; i++)
		{
			par[i] = i;
			sz[i] = 1;
		}
		namesCount = 0;
		m.clear();
		while (n--)
		{
			string s1, s2;
			cin >> s1 >> s2;
			cout << Union(getHash(s1), getHash(s2)) << endl;
		}
	}
	return 0;
}