#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;
unordered_map<string, int> cnt;

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> s;
		cnt.clear();
		n = min((int)s.length(), 10);
		for (int mask = 1; mask < (1 << n); mask++)
		{
			string s2 = "";
			for (int i = 0; i < n; i++)
				if (mask & (1 << i))
					s2 = s2 + s[i];
			cnt[s2]++;
		}
		bool found = false;
		for (int mask = 1; mask < (1 << n); mask++)
		{
			string s2 = "";
			for (int i = 0; i < n; i++)
				if (mask & (1 << i))
					s2 = s2 + s[i];
			if (cnt[s2] == 2)
			{
				found = true;
				cout << s2 << endl;
				break;
			}
		}
		if (!found)
			cout << -1 << endl;
	}
	return 0;
}