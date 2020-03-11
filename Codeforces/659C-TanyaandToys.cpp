/*
	SubmissionId	:	17040080
	ContestId	:	659
	Index	:	C
	ProblemName	:	Tanya and Toys
	ProblemTags	:	['greedy', 'implementation']
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

unordered_map<int, bool> cnt;
int n, m, sum;
vector<int> ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		cnt[x] = true;
	}
	for (int i = 1; i <= INF; i++)
	{
		if (sum + i > m)
			break;
		if (cnt.count(i) == 0)
		{
			sum += i;
			ans.push_back(i); 
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}