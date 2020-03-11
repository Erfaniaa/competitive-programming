/*
	SubmissionId	:	18456527
	ContestId	:	681
	Index	:	A
	ProblemName	:	A Good Contest
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

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		string s;
		int a, b;
		cin >> s >> a >> b;
		if (a >= 2400 && b > a)
			flag = true;
	}
	if (flag == true)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}