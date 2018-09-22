/*
	SubmissionId	:	5261485
	ContestId	:	367
	Index	:	B
	ProblemName	:	Sereja ans Anagrams
	ProblemTags	:	['binary search', 'data structures']
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
#define MAXN 200010

ll a[MAXN], b[MAXN], m, n, p;
vector<int> ans;
map<int, int> cntA, cntB;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> p;
	FOR (i, 1, n)
		cin >> a[i];
	FOR (i, 1, m)
		cin >> b[i];
	int mp = min(n, p);
	FOR (i, 1, m)
		cntB[b[i]]++;
	FOR (i, 1, mp)
	{
		cntA.clear();
		int out = 0;
		if (i + (m - 1) * p > n)
			break;
		for (int j = i; j <= i + (m - 1) * p; j += p)
		{
			if (cntA[a[j]] >= cntB[a[j]])
				out++;
			cntA[a[j]]++;
		}
		if (out == 0)
			ans.pb(i);
		// debug(i);
		// debug(out);
		// FOR (t, 1, 5)
		// 	cerr << t << ": " << cntA[t] << endl;
		int k = i + p;
		while (k + (m - 1) * p <= n)
		{
			if (cntA[a[k - p]] > cntB[a[k - p]])
				out--;
			cntA[a[k - p]]--;
			if (cntA[a[k + (m - 1) * p]] >= cntB[a[k + (m - 1) * p]])
				out++;
			cntA[a[k + (m - 1) * p]]++;
			if (out == 0)
				ans.pb(k);
			// debug(k);
			// debug(out);
			// FOR (t, 1, 5)
			// 	cerr << t << ": " << cntA[t] << endl;
			k += p;
		}
	}
	sort(ALL(ans));
	cout << SZ(ans) << endl;
	FOR (i, 0, SZ(ans) - 1)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}