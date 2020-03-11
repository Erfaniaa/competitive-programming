/*
	SubmissionId	:	4710840
	ContestId	:	54
	Index	:	B
	ProblemName	:	Cutting Jigsaw Puzzle
	ProblemTags	:	['hashing', 'implementation']
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
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 10000

int xx, yy, ans, ansX = 10000, ansY = 100000;
char c[100][100];
bool correct;
map<string, bool> mark;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> yy >> xx;
	FOR (y, 0, yy - 1)
		FOR (x, 0, xx - 1)
			cin >> c[x][y];
	string s1, s2, s3, s4;
	FOR (y, 1, yy)
	{	
		if (yy % y == 0)
			FOR (x, 1, xx)
				if (xx % x == 0)
				{
					bool correct = true;
					mark.clear();
					int pX = xx / x;
					int pY = yy / y;
					FOR (y2, 0, pY - 1)
						FOR (x2, 0, pX - 1)
						{
							s1 = s2 = s3 = s4 = "";
							FOR (i, 0, y - 1)
								FOR (j, 0, x - 1)
									s1 += c[x * x2 + j][y * y2 + i];
							if (x == y)
								FORD (j, x - 1, 0)
									FOR (i, 0, y - 1)
										s2 += c[x * x2 + j][y * y2 + i];
							s3 = s1;
							s4 = s2;
							reverse(ALL(s3));
							reverse(ALL(s4));
							if (mark[s1])
							{
								correct = false;
								break;
							}
							if (x == y && mark[s2])
							{
								correct = false;
								break;
							}
							if (mark[s3])
							{
								correct = false;
								break;
							}
							if (x == y && mark[s4])
							{
								correct = false;
								break;
							}
							mark[s1] = true;
							mark[s2] = true;
							mark[s3] = true;
							mark[s4] = true;
						}
					if (correct)
					{
						// debug(x);
						// debug(y);
						ans++;
						if (x * y < ansX * ansY)
						{
							ansX = x;
							ansY = y;
						}
						else if (ansX * ansY == x * y && y < ansY)
						{
							ansX = x;
							ansY = y;
						}
					}

				}
	}
	cout << ans << endl;
	cout << ansY << " " << ansX << endl;
	return 0;
}