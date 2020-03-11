/*
	SubmissionId	:	5180387
	ContestId	:	45
	Index	:	C
	ProblemName	:	Dancing Lessons
	ProblemTags	:	['data structures']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<fstream>
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
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 200010

struct Tri
{
	int x, y, z;
	Tri(int _x = 0, int _y = 0, int _z = 0)	
	{
		x = _x;
		y = _y;
		z = _z;
	}
	bool operator < (Tri t) const
	{
		if (x != t.x)
			return x < t.x;
		if (y != t.y)
			return y < t.y;
		return z < t.z;
	}
};

int n, a[MAXN], l[MAXN], r[MAXN];
string s;
set<Tri> h;
vector<pii> ans;
bool mark[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cin >> s;
	FOR (i, 0, n - 1)
	{
		l[i] = i - 1;
		r[i] = i + 1;
		cin >> a[i];
	}
	FOR (i, 0, n - 2)
		if (s[i] != s[i + 1])
			h.insert(Tri(abs(a[i] - a[i + 1]), i, i + 1));
	while (SZ(h))
	{
		Tri t = *h.begin();
		h.erase(t);
		if (!mark[t.y] && !mark[t.z])
		{
			ans.pb(pii(t.y + 1, t.z + 1));
			mark[t.y] = mark[t.z] = true;
			r[l[t.y]] = r[t.z];
			l[r[t.z]] = l[t.y];
			if (l[t.y] >= 0 && r[t.z] <= n - 1)
				if (s[l[t.y]] != s[r[t.z]])
					h.insert(Tri(abs(a[l[t.y]] - a[r[t.z]]), l[t.y], r[t.z]));
		}
	}
	cout << SZ(ans) << endl;
	FOR (i, 0, SZ(ans) - 1)
		cout << ans[i].X << " " << ans[i].Y << endl;
	return 0;
}