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

bool isSimilar(int a, int b)
{
	stringstream ss1, ss2;
	string s1, s2;
	ss1 << a;
	ss2 << b;
	ss1 >> s1;
	ss2 >> s2;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	return (s1 == s2);
}

bool mark[MAXN];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	mark[1] = true;
	for (int i = 2; i <= MAXN; i++)
		if (!mark[i])
			for (int j = 2 * i; j <= MAXN; j += i)
				mark[j] = true;
	for (int i = 1000; i <= 9999; i++)
		if (!mark[i] && !mark[i + 3330] && !mark[i + 6660] && isSimilar(i, i + 3330) && isSimilar(i, i + 6660))
			cout << i << i + 3330 << i + 6660 << endl;
	return 0;
}