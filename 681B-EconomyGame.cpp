/*
	SubmissionId	:	18459147
	ContestId	:	681
	Index	:	B
	ProblemName	:	Economy Game
	ProblemTags	:	['brute force']
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
	for (int a = 0; a * 1234567 <= n; a++)
		for (int b = 0; a * 1234567 + b * 123456 <= n; b++)
			if ((n - (a * 1234567 + b * 123456)) % 1234 == 0)
			{
				cout << "YES" << endl;
				return 0;
			}
	cout << "NO" << endl;
	return 0;
}