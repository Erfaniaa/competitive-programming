/*
	SubmissionId	:	14443379
	ContestId	:	602
	Index	:	A
	ProblemName	:	Two Bases
	ProblemTags	:	['implementation']
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

long long a, b, n, bx, by;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> bx;
	for (int i = 1; i <= n; i++)
	{
		long long tmp;
		cin >> tmp;
		a = bx * a + tmp;
	}
	cin >> n >> bx;
	for (int i = 1; i <= n; i++)
	{
		long long tmp;
		cin >> tmp;
		b = bx * b + tmp;
	}
	if (a < b)
		cout << "<" << endl;
	if (a == b)
		cout << "=" << endl;
	if (a > b)
		cout << ">" << endl;
	return 0;
}