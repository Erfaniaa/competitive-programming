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
#define debug(x) cerr << #x << " = " << x << endl
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

int n, a[MAXN], b[MAXN], a2[MAXN], rev[MAXN], rev2[MAXN], s1, s2, s3, s4;
vector<pii> ans1, ans2, ans3, ans4;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR (i, 1, n)
	{
		cin >> a[i];
		rev2[i] = rev[i] = a2[i] = b[i] = a[i];
	}
	sort(b + 1, b + 1 + n);
	reverse(rev + 1, rev + 1 + n);
	reverse(rev2 + 1, rev2 + 1 + n);
	FOR (i, 1, n)
	{
		if (a[i] != b[i])
		{
			int l = i;
			int r = l;
			while (a[r] != b[i])
				r++;
			s1 += r - l + 1;
			FOR (j, l, (l + r) / 2)
				if (a[j] != a[r - (j - l)])
					swap(a[j], a[r - (j - l)]);
			ans1.pb(pii(l, r));
		}
	}
	FORD (i, n, 1)
	{
		if (a2[i] != b[i])
		{
			int r = i;
			int l = r;
			while (a2[l] != b[i])
				l--;
			s2 += r - l + 1;
			FOR (j, l, (l + r) / 2)
				if (a2[j] != a2[r - (j - l)])
					swap(a2[j], a2[r - (j - l)]);
			ans2.pb(pii(l, r));
		}
	}
////////////////////
	ans3.pb(pii(1, n));
	ans4.pb(pii(1, n));
	s3 = s4 = n;
	FOR (i, 1, n)
	{
		if (rev[i] != b[i])
		{
			int l = i;
			int r = l;
			while (rev[r] != b[i])
				r++;
			s3 += r - l + 1;
			FOR (j, l, (l + r) / 2)
				if (rev[j] != rev[r - (j - l)])
					swap(rev[j], rev[r - (j - l)]);
			ans3.pb(pii(l, r));
		}
	}
	FORD (i, n, 1)
	{
		if (rev2[i] != b[i])
		{
			int r = i;
			int l = r;
			while (rev2[l] != b[i])
				l--;
			s4 += r - l + 1;
			FOR (j, l, (l + r) / 2)
				if (rev2[j] != rev2[r - (j - l)])
					swap(rev2[j], rev2[r - (j - l)]);
			ans4.pb(pii(l, r));
		}
	}


	if ((double)s1 / n + SZ(ans1) > (double)s2 / n + SZ(ans2))
		swap(ans1, ans2);
	if ((double)s1 / n + SZ(ans1) > (double)s3 / n + SZ(ans3))
		swap(ans1, ans3);
	if ((double)s1 / n + SZ(ans1) > (double)s4 / n + SZ(ans4))
		swap(ans1, ans4);
	cout << SZ(ans1) << endl;
	FOR (i, 0, SZ(ans1) - 1)
		cout << ans1[i].X << " " << ans1[i].Y << endl;
	return 0;
}