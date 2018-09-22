/*
	SubmissionId	:	16805672
	ContestId	:	653
	Index	:	A
	ProblemName	:	Bear and Three Balls
	ProblemTags	:	['brute force', 'implementation', 'sortings']
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

int n, cnt[1010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		cnt[x]++;
	}
	for (int i = 1; i <= 1000; i++)
		if (cnt[i] && cnt[i - 1] && cnt[i + 1])
		{
			cout << "YES" << endl;
			return 0;
		}
	cout << "NO" << endl;
	return 0;
}