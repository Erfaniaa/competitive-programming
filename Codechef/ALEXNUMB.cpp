#include<iostream>

using namespace std;

#define ll long long
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)

int t, n, tmp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	FOR (tt, 1, t)
	{
		cin >> n;
		FOR (i, 1, n)
			cin >> tmp;
		cout << (ll)n * (ll)(n - 1) / 2 << "\n";
	}
	return 0;
}