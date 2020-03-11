/*
	SubmissionId	:	36924419
	ContestId	:	959
	Index	:	D
	ProblemName	:	Mahmoud and Ehab and another array construction task
	ProblemTags	:	['constructive algorithms', 'greedy', 'math', 'number theory']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010
#define MAXM 5000010

int n, a[MAXN], b[MAXN];
set<int> st;
bool isRemoved[MAXM], mark[MAXM]; //mark = notPrime
// vector<int> d[MAXM];

bool coprime(int x) {
	return !isRemoved[x];
}

void removePrime(int p) {
	// cout << "remPrime" << p << endl;
	for (int i = p; i < MAXM; i += p) {
		// st.erase(i);
		isRemoved[i] = true;
	}
}

void removeNumber(int x) {
	// // cout << "remNum" << x << endl;
	// for (int i = 0; i < d[x].size(); i++) {
	// 	// cout << d[x][i] << endl;
	// 	if (!mark[d[x][i]] && !isRemoved[d[x][i]])
	// 		removePrime(d[x][i]);
	// }

	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			if (!mark[i] && !isRemoved[i])
				removePrime(i);
			// if (i * i == x)
				// continue;
			int j = x / i;
			if (!mark[j] && !isRemoved[j])
				removePrime(j);
		}
	}
}

int main() {
	cin >> n;
	// n = 100000;
	isRemoved[1] = true;
	// for (int i = 2; i < MAXM; i++)
		// st.insert(i);
	for (int i = 0; i < n; i++)
		cin >> a[i];
		// a[i] = i + 10;
	mark[1] = true;
	for (int i = 1; i < MAXM; i++)
		if (!mark[i])
			for (int j = 2 * i; j < MAXM; j += i) {
				// if (i != j)
					mark[j] = true;
				// d[j].push_back(i);
			}
	// cout << "salam" << endl;
	bool flag = false;
	int k = -1;
	for (int i = 0; i < n; i++) {
		if (!coprime(a[i])) {
			k = i;
			flag = true;
			break;
		}
		removeNumber(a[i]);
	}
	// cout << "salam2" << endl;
	// cout << k << "**" << endl;
	if (!flag) {
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	else {
		for (int i = 0; i < k; i++)
			b[i] = a[i];

		for (int i = a[k]; i < MAXM; i++)
			if (coprime(i)) {
				b[k] = i;
				removeNumber(i);
				break;
			}

		int last = 1;

		for (int i = k + 1; i < n; i++) {
			// b[i] = *st.begin();
			for (int j = last + 1; j < MAXM; j++)
				if (coprime(j)) {
					b[i] = j;
					removeNumber(j);
					break;
				}
			last = b[i];
			removeNumber(b[i]);
		}

		for (int i = 0; i < n; i++)
			cout << b[i] << " ";
		cout << endl;	
	}
	return 0;
}