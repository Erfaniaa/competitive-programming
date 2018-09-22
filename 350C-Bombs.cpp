/*
	SubmissionId	:	4624782
	ContestId	:	350
	Index	:	C
	ProblemName	:	Bombs
	ProblemTags	:	['greedy', 'implementation', 'sortings']
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
#define mp make_pair
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

int n;
pii bombs[MAXN];

bool compare(pii b1, pii b2)
{
	return (abs(b1.X) + abs(b1.Y) < abs(b2.X) + abs(b2.Y));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int ans = 0;
	FOR (i, 0, n - 1)
	{
		cin >> bombs[i].X >> bombs[i].Y;
		if (bombs[i].X == 0 || bombs[i].Y == 0)
			ans += 4;
		else
			ans += 6;
	}
	sort(bombs, bombs + n, compare);
	cout << ans << endl;
	FOR (i, 0, n - 1)
	{
		int x = bombs[i].X;
		int y = bombs[i].Y;
		if (x == 0)
		{
			if (y > 0)
			{
				cout << "1 " << y << " U" << endl;
				cout << 2 << endl;
				cout << "1 " << y << " D" << endl;
				cout << 3 << endl;
			}
			else
			{
				cout << "1 " << -y << " D" << endl;
				cout << 2 << endl;
				cout << "1 " << -y << " U" << endl;
				cout << 3 << endl;
			}
		}
		else if (y == 0)
		{
			if (x > 0)
			{
				cout << "1 " << x << " R" << endl;
				cout << 2 << endl;
				cout << "1 " << x << " L" << endl;
				cout << 3 << endl;
			}
			else
			{
				cout << "1 " << -x << " L" << endl;
				cout << 2 << endl;
				cout << "1 " << -x << " R" << endl;
				cout << 3 << endl;
			}
		}
		else
		{
			if (x > 0)
			{
				cout << "1 " << x << " R" << endl;
				if (y > 0)
				{
					cout << "1 " << y << " U" << endl;
					cout << 2 << endl;
					cout << "1 " << y << " D" << endl;
				}
				else
				{
					cout << "1 " << -y << " D" << endl;
					cout << 2 << endl;
					cout << "1 " << -y << " U" << endl;
				}
				cout << "1 " << x << " L" << endl;
				cout << 3 << endl;
			}
			else
			{
				cout << "1 " << -x << " L" << endl;
				if (y > 0)
				{
					cout << "1 " << y << " U" << endl;
					cout << 2 << endl;
					cout << "1 " << y << " D" << endl;
				}
				else
				{
					cout << "1 " << -y << " D" << endl;
					cout << 2 << endl;
					cout << "1 " << -y << " U" << endl;
				}
				cout << "1 " << -x << " R" << endl;
				cout << 3 << endl;
			}
		}
	}
	return 0;
}