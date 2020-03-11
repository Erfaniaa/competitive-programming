#include <iostream>
#include <cstring>

using namespace std;

#define SZ(x) ((int)((x).size()))
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)

int cnt1[256], cnt2[256], tt, ans;
string s, t;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> tt;
	while (tt--)
	{
		cin >> s;
		cin >> t;
		memset(cnt1, 0, sizeof cnt1);
		memset(cnt2, 0, sizeof cnt2);
		ans = 0;
		FOR (i, 0, SZ(s) - 1)
			cnt1[s[i]]++;
		FOR (i, 0, SZ(t) - 1)
			cnt2[t[i]]++;
		FOR (i, 0, 255)
			ans += min(cnt1[i], cnt2[i]);
		cout << ans << endl;
	}
	return 0;
}