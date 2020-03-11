/*
	SubmissionId	:	17724185
	ContestId	:	670
	Index	:	B
	ProblemName	:	Game of Robots
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

int n, a[MAXN];
long long k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	long long cnt = 0;
	while ((cnt + 1) * (cnt + 2) <= 2 * k)
		cnt++;
	long long dif = k - (cnt + 1) * cnt / 2;
	if (dif == 0)
		cout << a[cnt] << endl;
	else
		cout << a[dif] << endl;
	return 0;
}