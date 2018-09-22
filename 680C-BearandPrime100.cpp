/*
	SubmissionId	:	18327473
	ContestId	:	680
	Index	:	C
	ProblemName	:	Bear and Prime 100
	ProblemTags	:	['constructive algorithms', 'number theory']
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

int cnt, p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 16; i++)
	{
		cout << p[i] << endl;
		string s;
		cin >> s;
		if (s == "yes")
			cnt++;
		if (s == "yes" && p[i] * p[i] <= 100)
		{
			cout << p[i] * p[i] << endl;
			cin >> s;
			if (s == "yes")
			{
				cout << "composite" << endl;
				fflush(stdout);
				return 0;
			}
		}

	}
	if (cnt == 0 || cnt == 1)
		cout << "prime" << endl;
	else
		cout << "composite" << endl;
	fflush(stdout);
	return 0;
}