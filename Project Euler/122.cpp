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
#define MAXN 210

vector<int> path;
int ans[MAXN], n;
long long sum;

void solve(int x)
{
	if (x <= n && SZ(path) <= 11)
	{
		ans[x] = min(ans[x], SZ(path));
		path.push_back(x);
		for (int i = 0; i < SZ(path); i++)
			solve(x + path[i]);
		path.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		ans[i] = INF;
	solve(1);
	for (int i = 1; i <= n; i++)
	{
		sum += ans[i];
		 	cerr << i << ": " << ans[i] << endl;
	}
	cout << sum << endl;
	return 0;
}