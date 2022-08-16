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

int p[] = {1, 2, 3, 5, 7, 11, 13, 17};
long long sum;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s = "0123456789";
	do
	{
		bool flag = true;
		long long x;
		stringstream ss1;
		ss1 << s;
		ss1 >> x;
		for (int i = 1; i <= 7; i++)
		{
			stringstream ss;
			long long a;
			ss << s.substr(i, 3);
			ss >> a;
			if (a % p[i] != 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
			sum += x;
	} while (next_permutation(s.begin(), s.end()));
	cout << sum << endl;
	return 0;
}