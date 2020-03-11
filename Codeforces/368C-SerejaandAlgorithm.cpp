/*
	SubmissionId	:	5261494
	ContestId	:	368
	Index	:	C
	ProblemName	:	Sereja and Algorithm 
	ProblemTags	:	['brute force', 'implementation']
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

int sum[MAXN][5], m;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	cin >> m;
	int l = SZ(s);
	FOR (i, 1, l)
	{
		int ch = s[i - 1] - 'x';
		FOR (j, 0, 2)
			sum[i][j] = sum[i - 1][j];
		sum[i][ch]++;
	}
	bool flag;
	FOR (i, 1, m)
	{
		int a, b, x, y, z, mn;
		flag = true;
		cin >> a >> b;
		x = sum[b][0] - sum[a - 1][0];
		y = sum[b][1] - sum[a - 1][1];
		z = sum[b][2] - sum[a - 1][2];
		mn = min(x, min(y, z));
		x -= mn;
		y -= mn;
		z -= mn;
		if (x >= 2 || y >= 2 || z >= 2)
			flag = false;
		if (b - a + 1 <= 2)
			flag = true;
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}