/*
	SubmissionId	:	4810407
	ContestId	:	354
	Index	:	C
	ProblemName	:	Vasya and Beautiful Arrays
	ProblemTags	:	['brute force', 'dp', 'number theory']
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
#define MAXN 1000010

int n, k, sum, mn = INF, mx;
int cnt[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	FOR (i, 1, n)
	{
		int a;
		cin >> a;
		mn = min(mn, a);
		mx = max(mx, a);
		cnt[max(a - k, 1)]++;
		cnt[a + 1]--;
	}
	FOR (i, 1, mx)
		cnt[i] += cnt[i - 1];
	int ans = min(mn, k);
	FORD (i, mn, k)
	{
		sum = 0;
		for (int j = i; j <= mx; j += i)
			sum += cnt[j];
		if (sum >= n)
		{
			ans = max(ans, i);
			break;
		}
	}
	cout << ans << endl;
	return 0;
}