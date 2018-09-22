/*
	SubmissionId	:	6488795
	ContestId	:	425
	Index	:	A
	ProblemName	:	Sereja and Swaps
	ProblemTags	:	['brute force', 'sortings']
	ProgrammingLanguage	:	GNU C++0x
	Verdict	:	OK
*/

#include <bits/stdc++.h>
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
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

int n, k, mx;
int a[MAXN];
vector<int> v, v2, v3;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	mx = -INF;
	FOR (i, 1, n)
	{
		cin >> a[i];
		if (a[i] > mx)
			mx = a[i];
	}
	FOR (i, 1, n)
	{
		v.clear();
		FOR (j, i, n)
		{
			int sum = 0;
			v.pb(a[j]);
			sort(ALL(v));
			v2.clear();
			FOR (l, 1, n)
				if (l < i || l > j)
					v2.pb(a[l]);
			sort(ALL(v2));
			reverse(ALL(v2));
			int kp = min(k, SZ(v));
			kp = min(kp, SZ(v2));
			v3.clear();
			FOR (i, 0, kp - 1)
			{
				v3.pb(v[i]);
				v3.pb(v2[i]);
			}
			sort(ALL(v3));
			reverse(ALL(v3));
			FOR (l, 0, kp - 1)
				sum += v3[l];
			FOR (l, kp, SZ(v) - 1)
				sum += v[l];
			if (sum > mx)
				mx = sum;
		}
	}
	cout << mx << endl;
	return 0;
}