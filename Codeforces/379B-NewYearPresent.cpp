/*
	SubmissionId	:	5575366
	ContestId	:	379
	Index	:	B
	ProblemName	:	New Year Present
	ProblemTags	:	['constructive algorithms', 'implementation']
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
#define MAXN 100010

int a[400], n, sum;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
	{
		cin >> a[i];
		sum += a[i];
	}
	int d = 1, idx = 1;
	while (1)
	{
		if (idx + d == n + 1 || idx + d == 0)
			d = -d;
		if (a[idx])
		{
			a[idx]--;
			sum--;
			cout << 'P';
		}
		if (sum == 0)
			return 0;
		idx += d;
		if (d == 1)
			cout << 'R';
		else
			cout << 'L';
	}
	return 0;
}