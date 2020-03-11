#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
const int BASE = 701;
int h[MAXN], p[MAXN];
string s;

int getHash(int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
	cin >> s;
	int a, b, c, d;
	cin >> a >> b;
	cin >> c >> d;
	a--, b--, c--, d--;
	h[0] = s[0];
	for (int i = 1; i < s.length(); i++)
		h[i] = h[i - 1] * BASE + s[i];
	p[0] = 1;
	for (int i = 1; i <= s.length(); i++)
		p[i] = p[i - 1] * BASE;
	if (getHash(a, b) == getHash(c, d))
		cout << "Equal" << endl;
	else
		cout << "not Equal" << endl;
}