/*
	SubmissionId	:	36913642
	ContestId	:	959
	Index	:	B
	ProblemName	:	Mahmoud and Ehab and the message
	ProblemTags	:	['dsu', 'greedy', 'implementation']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

const long long INF = 1000000100;
const long long MAXN = 200010;

int n, k, m;
int tmp[MAXN];
string s[MAXN];
long long ans;
map<string, long long> cost;

int main() {
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	for (int i = 1; i <= n; i++) {
		long long x;
		cin >> x;
		cost[s[i]] = x;
	}
	for (int i = 1; i <= k; i++) {
		int cnt;
		long long mn = INF;
		cin >> cnt;
		for (int j = 1; j <= cnt; j++) {
			cin >> tmp[j];
			mn = min(mn, cost[s[tmp[j]]]);
		}
		for (int j = 1; j <= cnt; j++) {
			cost[s[tmp[j]]] = mn;
		}
	}
	for (int i = 1; i <= m; i++) {
		string st;
		cin >> st;
		ans += cost[st];
	}
	cout << ans << endl;
	return 0;
}