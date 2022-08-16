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
#define MAXN (50 * 1000000 + 1)

bool b[MAXN], p[MAXN], flag[MAXN];
vector<int> primes;
int ans, n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//cin >> n;
	n = MAXN;
	p[1] = true;
	for (int i = 2; i * i <= n; i++)
		if (!p[i])
			for (int j = i * i; j <= n; j += i)
				p[j] = true;
	for (int i = 2; i <= n; i++)
		if (!p[i])
			primes.push_back(i);
	for (int i = 0; i < SZ(primes); i++)
	{
		if (primes[i] * primes[i] >= n)
			break;
		for (int j = 0; j < SZ(primes); j++)
		{
			if (primes[j] * primes[j] * primes[j] >= n)
				break;
			if (primes[i] * primes[i] + primes[j] * primes[j] * primes[j] >= n)
				break;
			for (int k = 0; k < SZ(primes); k++)
			{
				if (primes[k] * primes[k] * primes[k] * primes[k] > n)
					break;
				if (primes[i] * primes[i] + primes[j] * primes[j] * primes[j] + primes[k] * primes[k] * primes[k] * primes[k] > n)
					break;
				flag[primes[i] * primes[i] + primes[j] * primes[j] * primes[j] + primes[k] * primes[k] * primes[k] * primes[k]] = true;			}
		}
	}
	for (int i = 1; i <= n; i++)
		ans += flag[i];
	cout << ans << endl;
	return 0;
}