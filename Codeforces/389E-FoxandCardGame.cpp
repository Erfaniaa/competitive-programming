/*
	SubmissionId	:	5890037
	ContestId	:	389
	Index	:	E
	ProblemName	:	Fox and Card Game
	ProblemTags	:	['greedy', 'implementation']
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

int n, s[2], sum, sum1;
vector<int> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
	{
		int cnt;
		cin >> cnt;
		FOR (j, 1, cnt)
		{
			int a;
			cin >> a;
			sum += a;
			if (j * 2 - 1 == cnt)
				v.pb(a);
			if (j * 2 - 1 < cnt)
				sum1 += a;
		}		
	}
	sort(ALL(v), greater<int>());
	FOR (i, 0, SZ(v) - 1)
		s[i % 2] += v[i];
	sum1 += s[0];
	cout << sum1 << " " << sum - sum1 << endl;
	return 0;
}