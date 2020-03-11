/*
	SubmissionId	:	17782451
	ContestId	:	673
	Index	:	A
	ProblemName	:	Bear and Game
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

int n, a[200];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a[x] = 1;
	}
	for (int i = 1; i <= 90; i++)
	{
		int sum = 0;
		for (int j = i; j <= i + 14 && j <= 90; j++)
			sum += (1 - a[j]);
		if (sum == 15)
		{
			cout << i + 14 << endl;
			return 0;
		}
	}
	cout << 90 << endl;
	return 0;
}