#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400010;

int n, tc, newIdx[MAXN], ans[MAXN];
pair<int, int> a[MAXN], b[MAXN];

int main() {
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			a[i].second = i;
			cin >> a[i].first;
			b[i] = a[i];
		}
		sort(b, b + n);
		for (int i = 0; i < n; i++) {
			newIdx[b[i].second] = i; 
		}
		for (int i = 0; i < n; i++) {
			ans[i] = b[(newIdx[i] + n / 2) % n].first;
		}
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (ans[i] == a[i].first) {
				cout << "No" << endl;
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "Yes" << endl;
			for (int i = 0; i < n; i++) {
				cout << ans[i];
				// cout << 0;
				if (i == n - 1)
					cout << endl;
				else
					cout << " ";
			}
		}
	}
	return 0;
}
