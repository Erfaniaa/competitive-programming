/*
	SubmissionId	:	16788333
	ContestId	:	645
	Index	:	B
	ProblemName	:	Mischievous Mess Makers
	ProblemTags	:	['greedy', 'math']
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

long long n, a;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> a;
	if (a >= n / 2)
		cout << n * (n - 1) / 2 << endl;
	else
		cout << 2 * a * n - a * (a + 1) - a * a << endl;
	return 0;
}