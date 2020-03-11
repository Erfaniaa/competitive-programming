/*
	SubmissionId	:	18566734
	ContestId	:	682
	Index	:	E
	ProblemName	:	Alyona and Triangles
	ProblemTags	:	['geometry', 'two pointers']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

struct Point
{
	int x, y;
	Point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}
	Point operator + (Point p)
	{
		return Point(x + p.x, y + p.y);
	}
	Point operator - (Point p)
	{
		return Point(x - p.x, y - p.y);
	}
	bool operator < (Point p)
	{
		if (x != p.x)
			return x < p.x;
		return y < p.y;
	}
} p[5010];

long long s;
int n;
vector <Point> convex;

inline long long cross(Point p1, Point p2)
{
	return (long long)p1.x * (long long)p2.y - (long long)p1.y * (long long)p2.x;
}

inline long long area(Point p1, Point p2, Point p3)
{
	return cross(p1 - p2, p3 - p2);
}

inline void convexHull()
{
	vector <Point> up;
	sort(p, p + n);
	up.push_back(p[0]);	
	up.push_back(p[1]);
	for (int i = 2; i < n; i++)
	{
		while (up.size() >= 2 && area(up[up.size() - 2], up[up.size() - 1], p[i]) < 0)
			up.pop_back();
		up.push_back(p[i]);
	}
	vector <Point> down;
	reverse(p, p + n);
	down.push_back(p[0]);	
	down.push_back(p[1]);
	for (int i = 2; i < n; i++)
	{
		while (down.size() >= 2 && area(down[down.size() - 2], down[down.size() - 1], p[i]) < 0)
			down.pop_back();
		down.push_back(p[i]);
	}
	for (int i = 0; i < up.size(); i++)
		convex.push_back(up[i]);
	for (int i = 1; i < down.size() - 1; i++)
		convex.push_back(down[i]);
}

Point a, b, c;
long long maxArea, tmpArea, lastArea;

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;
	convexHull();
	for (int i = 0; i < convex.size(); i++)
	{
		int k = i + 1;
		if (i + 2 >= convex.size())
			break;
		for (int j = i + 1; j <= k; j++)
		{
			lastArea = abs(area(convex[i], convex[j], convex[k]));
			while (k + 1 < convex.size() && 
				(tmpArea = abs(area(convex[i], convex[j], convex[k + 1]))) >= lastArea)
			{
				k++;
				lastArea = tmpArea;
			}
			if (maxArea < lastArea)
			{
				maxArea = lastArea;
				a = convex[i];
				b = convex[j];
				c = convex[k];
			}
		}
	}
	cout << (b - c + a).x << " " << (b - c + a).y << endl;
	cout << (c - b + a).x << " " << (c - b + a).y << endl;
	cout << (b - a + c).x << " " << (b - a + c).y << endl;
	return 0;
}