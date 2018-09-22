/*
	SubmissionId	:	6923480
	ContestId	:	442
	Index	:	B
	ProblemName	:	Andrey and Problem
	ProblemTags	:	['greedy', 'math', 'probabilities']
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
#define debug(x) cerr << #x << " = " << x << "\n"
#define INF (1000 * 1000 * 1000)
#define MAXN 110

int n;
long double p[MAXN], ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			long double sum = 0;
			for (int k = i; k <= j; k++)
			{
				long double tmp = p[k];
				for (int l = i; l <= j; l++)
					if (l != k)
						tmp = tmp * (1 - p[l]);
				sum = sum + tmp;
			}
			ans = max(ans, sum);
		}
	}
	cout.precision(11);
	cout << fixed << ans << endl;
	return 0;
}