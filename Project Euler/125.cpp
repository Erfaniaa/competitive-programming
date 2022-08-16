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
#define MAXN 100000010

bool mark[MAXN];
int n;
long long sum;

bool isPalindrome(int x)
{
	stringstream ss;
	string s1, s2;
	ss << x;
	ss >> s1;
	s2 = s1;
	reverse(s2.begin(), s2.end());
	return s1 == s2;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	mark[0] = true;
	for (int i = 1; i * i <= n; i++)
	{
		long long tmp = i * i;
		for (int j = i + 1; j * j <= n; j++)
		{
			tmp += j * j;
			if (tmp > n)
				break;
			if (isPalindrome(tmp))
			{
				if (!mark[tmp])
					sum += tmp;
				mark[tmp] = true;
			}
		}
	}
	cout << sum << endl;
	return 0;
}