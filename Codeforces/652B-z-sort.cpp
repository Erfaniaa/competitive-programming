/*
	SubmissionId	:	16925623
	ContestId	:	652
	Index	:	B
	ProblemName	:	z-sort
	ProblemTags	:	['sortings']
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
#define MAXN 1010

int n, a[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n / 2; i++)
		cout << a[i] << " " << a[i + (n + 1) / 2] << " ";
	if (n & 1)
		cout << a[n / 2] << endl;
	return 0;
}