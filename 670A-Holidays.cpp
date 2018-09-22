/*
	SubmissionId	:	17721119
	ContestId	:	670
	Index	:	A
	ProblemName	:	Holidays
	ProblemTags	:	['brute force', 'constructive algorithms', 'greedy', 'math']
	ProgrammingLanguage	:	GNU C++11
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
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int mn = INF;
	int mx = -1;
	for (int start = 0; start < 7; start++)
	{
		int tmp = 0;
		for (int i = start; i < n + start; i++)
			if (i % 7 == 5 || i % 7 == 6)
				tmp++; 
		mn = min(mn, tmp);
		mx = max(mx, tmp);
	}
	cout << mn << " " << mx << endl;
	return 0;
}