#include <bits/stdc++.h>

using namespace std;

int t;
string n;

inline bool isSmallerOrEqual(string& s1, string& s2) {
	if (s1 == s2)
		return true;
	if (s1 == "0")
		return true;
	int i = 0, j = 0;
	int len1 = s1.size(), len2 = s2.size();
	while (i + 1 < s1.size() && s1[i] == '0') {
		i++;
		len1--;
	}
	while (j + 1 < s2.size() && s2[j] == '0') {
		j++;
		len2--;
	}
	if (len1 < len2)
		return true;
	if (len1 > len2) {
		return false;
	}
	while (i < s1.size() && j < s2.size()) {
		if (s1[i] > s2[j]) {
			return false;
		}
		if (s1[i] < s2[j]) {
			return true;
		}
		i++;
		j++;
	}
	return true;
}

inline string reverse(string s) {
	reverse(s.begin(), s.end());
	return s;
}

inline bool updateAns(string &s, string &sRev, string &ans, string &ansRev) {
	if (isSmallerOrEqual(sRev, n) && !isSmallerOrEqual(s, ansRev)) {
		ansRev = s;
		ans = sRev;
		return true;
	}
	else
		return false;
}

void generateLen(int l, string &ans, string &ansRev) {
	string tmp = string(max(l - 1, 0), '0') + "1";
	string tmpRev = reverse(tmp);
	updateAns(tmp, tmpRev, ans, ansRev);
	for (int i = 0; i < l; i++) {
		for (int j = 0; j <= 9; j++) {
			if (i == l - 1 && j == 0)
				continue;
			if (i == 0 && j == 0)
				continue;
			tmp[i] = (char)(48 + j);
			tmpRev[l - 1 - i] = tmp[i];
			if (!isSmallerOrEqual(tmpRev, n)) {
				tmp[i] = max((int)tmp[i] - 1, 48);
				tmpRev[l - 1 - i] = tmp[i];
				break;
			}
			updateAns(tmp, tmpRev, ans, ansRev);
		}
	}
}

char tmpN[100010];

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cin >> t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", tmpN);
		n = string(tmpN);
		// cin >> n;
		string ans = "1", ansRev = "1";
		generateLen(n.size(), ans, ansRev);
		if (n.size() > 1)
			generateLen((int)n.size() - 1, ans, ansRev);
		printf("%s\n", ans.data());
		// cout << ans << "\n";
	}
	return 0;
}