/*
	SubmissionId	:	14761138
	ContestId	:	598
	Index	:	C
	ProblemName	:	Nearest vectors
	ProblemTags	:	['geometry', 'sortings']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define x first
#define y second

struct Vector
{
	long long x, y, idx;
	Vector()
	{
		x = y = idx = 0;
	}
	bool operator < (const Vector& b)
	{
		return atan2(y, x) < atan2(b.y, b.x); 
	}
};

int main()
{
	int n;
	long double pi = acos(-1);
	cin >> n;
	Vector v[200010];
	for (int i = 0; i < n; i++)
		cin >> v[i].x >> v[i].y;
	for (int i = 0; i < n; i++)
		v[i].idx = i + 1;
	sort(v, v + n);
	v[n] = v[0];
	long double minAngle = 10;
	int ans1, ans2;
	for (int i = 0; i < n; i++)
	{
		Vector a = v[i];
		long double angleA = atan2((long double)a.y, (long double)a.x);
		Vector b = v[i + 1];
		long double angleB = atan2((long double)b.y, (long double)b.x);
		long double delta = fabs(angleB - angleA);
		if (delta > pi)
			delta = 2 * pi - delta;
		if (delta < minAngle)
		{
			ans1 = a.idx;
			ans2 = b.idx;
			minAngle = delta;
		}
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}

/*
3
0 1
1 0
0 -1
*/