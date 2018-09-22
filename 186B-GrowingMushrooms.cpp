/*
	SubmissionId	:	1658663
	ContestId	:	186
	Index	:	B
	ProblemName	:	Growing Mushrooms
	ProblemTags	:	['greedy', 'sortings']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	double t1, t2, k, l[1000];
	cin >> n >> t1 >> t2 >> k;
	double a, b;
	map<double, vector<int> > m;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		double l1 = a * t1 * (100.0 - k) / 100.0 + b * t2;
		double l2 = b * t1 * (100.0 - k) / 100.0 + a * t2;
		//cout << l1 << " " << l2;
		if (l1 > l2)
			l[i] = l1;
		else
			l[i] = l2;
		m[l[i]].push_back(i);
	}
	sort(l, l + n);
	cout.precision(2);
	for (int j = 0; j < (int)(m[l[n - 1]].size()); j++)
		cout << m[l[n - 1]][j] + 1 << " " << fixed << l[n - 1] << endl;
	for (int i = n - 2; i >= 0; i--)
	{
		if (l[i] != l[i + 1])
			for (int j = 0; j < (int)(m[l[i]].size()); j++)
				cout << m[l[i]][j] + 1 << " " << fixed << l[i] << endl;
	}
	//system("pause");
	//return 0;
}
