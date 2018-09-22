/*
	SubmissionId	:	19335442
	ContestId	:	701
	Index	:	B
	ProblemName	:	Cells Not Under Attack
	ProblemTags	:	['math']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int m;
long long cells, n;
bool row[100010], col[100010];
unordered_set<int> rows, cols;

int main()
{
	cin >> n >> m;
	cells = n * n;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		if (!row[x] && !col[y])
			cells--;
		if (!row[x])
			cells -= n - 1;
		if (!col[y])
			cells -= n - 1;
		long long r = rows.size();
		long long c = cols.size();
		if (row[x])
			r--;
		if (col[y])
			c--;
		if (row[x])
			c = 0;
		if (col[y])
			r = 0;
		cells += r + c;
		rows.insert(x);
		cols.insert(y);
		row[x] = col[y] = true;
		cout << cells << " ";
	}
	return 0;
}