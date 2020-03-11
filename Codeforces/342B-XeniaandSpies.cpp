/*
	SubmissionId	:	4427196
	ContestId	:	342
	Index	:	B
	ProblemName	:	Xenia and Spies
	ProblemTags	:	['brute force', 'greedy', 'implementation']
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
#define MAXN 100010

struct Three
{
	int t, l, r;
	Three (int _t = 0, int _l = 0, int _r = 0)
	{
		t = _t;
		l = _l;
		r = _r;
	}
} times[MAXN];

int n, m, s, f, pos;

int search(int t, int x, int y)
{
	int m = (x + y) / 2;
	if (times[m].t == t)
		return m;
	if (x >= y)
		return -1;
	if (times[m].t < t)
		return search(t, m + 1, y);
	else
		return search(t, x, m - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> s >> f;
	FOR (i, 0, m - 1)
		cin >> times[i].t >> times[i].l >> times[i].r;
	pos = s;
	int t = 0;
	while (pos < f)
	{
		t++;
		int idx = search(t, 0, m - 1);
		if (idx == -1)
		{
			cout << "R";
			pos++;
		}
		else
		{
			if (times[idx].l - 1 <= pos && times[idx].r >= pos)
				cout << "X";
			else
			{
				cout << "R";
				pos++;
			}
		}
	}
	while (pos > f)
	{
		t++;
		int idx = search(t, 0, m - 1);
		if (idx == -1)
		{
			cout << "L";
			pos--;
		}
		else
		{
			if (times[idx].l <= pos && times[idx].r + 1 >= pos)
				cout << "X";
			else
			{
				cout << "L";
				pos--;
			}
		}
	}
	return 0;
}
