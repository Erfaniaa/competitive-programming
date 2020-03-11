/*
	SubmissionId	:	15656748
	ContestId	:	618
	Index	:	C
	ProblemName	:	Constellation
	ProblemTags	:	['geometry', 'implementation']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

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
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

struct Point
{
	long long x, y;
	int idx;
	inline Point(long long _x = 0, long long _y = 0, int _idx = 0)
	{
		x = _x;
		y = _y;
		idx = _idx;
	}
	inline bool operator < (Point p)
	{
		if (x != p.x)
			return x < p.x;
		if (y != p.y)
			return y < p.y;
		return idx < p.idx;
	}
};

inline long long cross(Point p1, Point p2)
{
	return p1.x * p2.y - p1.y * p2.x;
}

int n;
Point p[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		p[i] = Point(x, y, i);
	}
	sort(p + 1, p + n + 1);
	for (int i = 3; i <= n; i++)
	{
		if (cross(Point(p[i].x - p[1].x, p[i].y - p[1].y, 0), Point(p[i].x - p[2].x, p[i].y - p[2].y, 0)) != 0)
		{
			cout << p[1].idx << " " << p[2].idx << " " << p[i].idx << endl;
			return 0;
		}
	}
	return 0;
}