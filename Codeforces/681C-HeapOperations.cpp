/*
	SubmissionId	:	18480452
	ContestId	:	681
	Index	:	C
	ProblemName	:	Heap Operations
	ProblemTags	:	['data structures', 'greedy']
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

struct Pair
{
	long long x, y;
} ans[1000010];

//insert: 0
//getMin: 1
//removeMin: 2

multiset <long long> st;
long long n, a, cnt;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		if (s == "insert")
		{
			cin >> a;
			st.insert(a);
			ans[cnt].x = 0;
			ans[cnt++].y = a;
		}
		else if (s == "getMin")
		{
			cin >> a;
			while (st.size())
			{
				long long e = *(st.begin());
				if (e >= a)
					break;
				st.erase(st.begin());
				ans[cnt++].x = 2;
			}
			if (st.count(a) == 0)
			{
				st.insert(a);
				ans[cnt].x = 0;
				ans[cnt++].y = a;
			}
			ans[cnt].x = 1;
			ans[cnt++].y = a;
		}
		else if (s == "removeMin")
		{
			if (st.size() == 0)
			{
				// st.insert(-1000000000);
				ans[cnt].x = 0;
				ans[cnt++].y = -1000000000;
			}
			else
				st.erase(st.begin());
			ans[cnt++].x = 2;
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
	{
		if (ans[i].x == 0)
			cout << "insert " << ans[i].y << endl;
		if (ans[i].x == 1)
			cout << "getMin " << ans[i].y << endl;
		if (ans[i].x == 2)
			cout << "removeMin" << endl;
	}
	return 0;
}