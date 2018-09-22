/*
	SubmissionId	:	4709767
	ContestId	:	54
	Index	:	A
	ProblemName	:	Presents
	ProblemTags	:	['implementation']
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

vector<int> holidays;
int n, k, c;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	cin >> c;
	FOR (i, 1, c)
	{

		int a;
		cin >> a;
		holidays.pb(a);
	}	
	holidays.pb(1000);
	int x = 0;
	int ans = 0;
	int j = 0;
	while (x < n)
	{
		x = min(x + k, holidays[j]);
		while (x >= holidays[j])
			j++;
		if (x <= n)
			ans++;
	}
	cout << ans << endl;
	return 0;
}