/*
	SubmissionId	:	5796014
	ContestId	:	385
	Index	:	C
	ProblemName	:	Bear and Prime Numbers
	ProblemTags	:	['binary search', 'brute force', 'data structures', 'dp', 'implementation', 'math', 'number theory']
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
#define MAXN 10000010

unsigned int cnt[MAXN], sum[MAXN];
unsigned int n, m;
unsigned int mx;
unsigned int flag[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
	{
		unsigned int a;
		cin >> a;
		cnt[a]++;
		mx = max(mx, a);
	}
	cin >> m;
	FOR (i, 2, mx)
	{
		sum[i] = sum[i - 1];
		if (!flag[i])
			FOR (j, 1, mx / i)
			{
				flag[i * j] = true;
				sum[i] += cnt[i * j];
			}
	}
	FOR (i, 1, m)
	{
		unsigned int l, r;
		cin >> l >> r;
		cout << sum[min(r, mx)] - sum[min(l - 1, mx)] << endl;
	}
	return 0;
}