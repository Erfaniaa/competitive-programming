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

int rad[MAXN], a[MAXN];
int n, k;

bool compare(int x, int y)
{
	if (rad[x] != rad[y])
		return rad[x] < rad[y];
	else
		return x < y;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		rad[i] = 1;
	for (int i = 2; i <= n; i++)
		if (rad[i] == 1)
			for (int j = i; j <= n; j += i)
				rad[j] *= i;
	for (int i = 1; i <= n; i++)
		a[i] = i;
	sort(a + 1, a + n + 1, compare);
	cout << a[k] << endl;
	return 0;
}