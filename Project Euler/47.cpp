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
#define MAXN 10000010

bool mark[MAXN];
int dv[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	mark[1] = true;
	for (int i = 2; i <= MAXN; i++)
		if (!mark[i])
			for (int j = i; j <= MAXN; j += i)
			{
				mark[j] = true;
				dv[j]++;
			}
	for (int i = 1; i <= MAXN - 3; i++)
		if (dv[i] == 4 && dv[i + 1] == 4 && dv[i + 2] == 4 && dv[i + 3] == 4)
		{
			cout << i << endl;
			break;
		}
	return 0;
}