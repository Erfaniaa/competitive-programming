/*
	SubmissionId	:	4839080
	ContestId	:	55
	Index	:	B
	ProblemName	:	Smallest number
	ProblemTags	:	['brute force']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<fstream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF ((ll)1000 * 1000 * 1000 * 1000)
#define MAXN 10000

ll ans = INF;

ll operate(ll a, ll b, char o)
{
	if (o == '+')
		return a + b;
	else
		return a * b;
}

void solve(vector<ll> nums, vector<char> signs)
{
	if (SZ(nums) == 1)
	{
		ans = min(ans, nums[0]);
		return;
	}
	vector<ll> nums2;
	vector<char> signs2;
	signs2 = signs;
	signs2.erase(signs2.begin());
	FOR (i, 0, SZ(nums) - 1)
	{
		FOR (j, i + 1, SZ(nums) - 1)
		{
			nums2 = nums;
			ll x = operate(nums[i], nums[j], signs[0]);
			nums2[i] = x;
			nums2.erase(nums2.begin() + j);
			solve(nums2, signs2);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<ll> v;
	vector<char> c;
	FOR (i, 0, 3)
	{
		ll a;
		cin >> a;
		v.pb(a);
	}
	FOR (i, 1, 3)
	{
		char ch;
		cin >> ch;
		if (ch != ' ')
			c.pb(ch);
	}
	solve(v, c);
	cout << ans << endl;
	return 0;
}