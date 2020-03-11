/*
	SubmissionId	:	15650788
	ContestId	:	618
	Index	:	A
	ProblemName	:	Slime Combining
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

int a[MAXN], n, len;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	len = 1;
	a[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		len++;
		a[len] = 1;
		while (len >= 2 && a[len] == a[len - 1])
		{
			len--;
			a[len]++;
		}
	}
	for (int i = 1; i <= len; i++)
		cout << a[i] << " ";
	return 0;
}