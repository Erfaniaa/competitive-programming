#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)

int t, idx[300], cnt[300];
char rep[300];

bool compare(char c1, char c2)
{
	if (cnt[c1] != cnt[c2])
		return cnt[c1] < cnt[c2];
	return c1 < c2;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	cin.ignore();
	FOR (tt, 1, t)
	{
		string s1, s2, s3;
		getline(cin, s1);
		getline(cin, s2);
		s3 = s2;
		memset(cnt, 0, sizeof cnt);
		memset(idx, -1, sizeof idx);
		memset(rep, 0, sizeof rep);
		FOR (j, 0, SZ(s2) - 1)
		{
			s2[j] = tolower(s2[j]);
			if (idx[s2[j]] == -1)
				idx[s2[j]] = j;
			cnt[s2[j]]++;
		}
		string tmp = s2;
		s2 = "";
		FOR (i, 0, SZ(tmp) - 1)
			if ((tmp[i] >= 'a' && tmp[i] <= 'z') || (tmp[i] >= 'A' && tmp[i] <= 'Z'))
				s2.pb(tolower(tmp[i]));
		sort(ALL(s2), compare);
		s2.erase(unique(ALL(s2)), s2.end());
		s1.erase(0, s1.length() - s2.length());
		FOR (i, 0, SZ(s1) - 1)
			rep[s2[i]] = s1[i];
		FOR (i, 0, SZ(s3) - 1)
		{
			if (islower(s3[i]))
				s3[i] = rep[s3[i]];
			if (isupper(s3[i]))
				s3[i] = toupper(rep[tolower(s3[i])]);
		}
		cout << s3 << "\n";
	}
	return 0;
}