/*
	SubmissionId	:	5108402
	ContestId	:	362
	Index	:	C
	ProblemName	:	Insertion Sort
	ProblemTags	:	['data structures', 'dp', 'implementation', 'math']
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
#define MAXN 5010

int n, a[MAXN], inv, biggers[MAXN][MAXN];

int segmentBiggers(int val, int l, int r)
{
	return biggers[val][r] - biggers[val][l - 1];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
		cin >> a[i];
	FOR (i, 1, n)
		FOR (j, i + 1, n)
			if (a[i] > a[j])
				inv++;
	FOR (val, 0, n - 1)
		FOR (idx, 1, n)
		{
			biggers[val][idx] = biggers[val][idx - 1];
			if (a[idx] > val)
				biggers[val][idx]++;
		}
	int minDif = 5001 * 5001;
	FOR (i, 1, n)
		FOR (j, i + 1, n)
		{
			int dif = 1;
			if (a[i] > a[j])
				dif = -1;
			if (j >= i + 2)
			{
				int len = j - i - 1;
				int x = a[i];
				int y = a[j];
				dif += segmentBiggers(x, i + 1, j - 1);
				dif -= len - segmentBiggers(x, i + 1, j - 1);
				dif -= segmentBiggers(y, i + 1, j - 1);
				dif += len - segmentBiggers(y, i + 1, j - 1);
			}
			if (dif < minDif)
				minDif = dif;
		}
	int cnt = 0;
	FOR (i, 1, n)
		FOR (j, i + 1, n)
		{
			int dif = 1;
			if (a[i] > a[j])
				dif = -1;
			if (j >= i + 2)
			{
				int len = j - i - 1;
				int x = a[i];
				int y = a[j];
				dif += segmentBiggers(x, i + 1, j - 1);
				dif -= len - segmentBiggers(x, i + 1, j - 1);
				dif -= segmentBiggers(y, i + 1, j - 1);
				dif += len - segmentBiggers(y, i + 1, j - 1);
			}
			if (dif == minDif)
				cnt++;
		}
	cout << inv + minDif << " " << cnt << endl;
	return 0;
}