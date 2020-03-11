/*
	SubmissionId	:	17054448
	ContestId	:	659
	Index	:	A
	ProblemName	:	Round House
	ProblemTags	:	['implementation', 'math']
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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, n;
	cin >> n >> a >> b;
	a--;
	a = (a + b + 10000 * n) % n;
	cout << a + 1 << endl;
	return 0;
}