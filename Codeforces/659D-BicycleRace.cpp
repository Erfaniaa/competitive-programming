/*
	SubmissionId	:	17054170
	ContestId	:	659
	Index	:	D
	ProblemName	:	Bicycle Race
	ProblemTags	:	['geometry', 'implementation', 'math']
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
#define MAXN 10010

int n, ans;
pair<int, int> p[MAXN];

int dx[] = {0, +1, 0, -1};
int dy[] = {+1, 0, -1, 0};

pair<int, int> yekke(int idx)
{
	pair<int, int> ret = {p[idx + 1].X - p[idx].X, p[idx + 1].Y - p[idx].Y};
	if (ret.first)
		ret.first = ret.first / abs(ret.first);
	if (ret.second)
		ret.second = ret.second / abs(ret.second);
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	n++;
	for (int i = 0; i < n; i++)
		cin >> p[i].X >> p[i].Y;
	int k = 1;
	for (int i = 1; i < n - 1; i++)
	{
		k = (k + 4) & 3;
		pair<int, int> v = {dx[k], dy[k]}, e = yekke(i);
		if (e == v)
		{
			ans++;
			k++;
		}
		else
			k--;
	}

	k = (k + 4) & 3;
	pair<int, int> v = {dx[k], dy[k]}, e = yekke(0);
	if (e == v)
		ans++;

	cout << n - 1 - ans << endl;
	return 0;
}