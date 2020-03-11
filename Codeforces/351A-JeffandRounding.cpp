/*
	SubmissionId	:	4720593
	ContestId	:	351
	Index	:	A
	ProblemName	:	Jeff and Rounding
	ProblemTags	:	['dp', 'greedy', 'implementation', 'math']
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
#define MAXN 2010

int n, cnt;
double sum1, sum2;

int near(double a)
{
	double x = floor(a);
	double y = ceil(a);
	if (fabs(a - x) < fabs(y - a))
		return x;
	else
		return y;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, 2 * n)
	{
		double a;
		cin >> a;
		sum1 += a;
		sum2 += (int)a;
		if (a == (int)a)
			cnt++;
	}
	int ceils = 0;
	int k = min(2 * n - cnt, n);
	k = min(k, near(sum1 - sum2));
	ceils += k;
	sum2 += k;
	int l = min(cnt, n - ceils);
	ceils += l;
	sum2 += n - ceils;
	// debug(cnt);
	// debug(k);
	// debug(ceils);
	// debug(sum2);
	// debug(sum1);
	cout.precision(3);
	cout << fixed << fabs(sum2 - sum1) << endl;
	return 0;
}