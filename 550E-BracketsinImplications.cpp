/*
	SubmissionId	:	13703657
	ContestId	:	550
	Index	:	E
	ProblemName	:	Brackets in Implications
	ProblemTags	:	['constructive algorithms', 'greedy', 'implementation']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100010

int n, a[MAXN], sum;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (n == 1)
	{
		if (a[0])
			cout << "NO" << endl;
		else
			cout << "YES" << endl << a[0] << endl;
		return 0;
	}
	if (n == 2)
	{
		if (a[0] && !a[1])
			cout << "YES" << endl << "1->0" << endl;
		else
			cout << "NO" << endl;
		return 0;
	}
	if (a[n - 1])
	{
		cout << "NO" << endl;
		return 0;
	}
	if (sum == n - 2 && !a[n - 1] && !a[n - 2])
	{
		cout << "NO" << endl;
		return 0;
	}
	if (a[n - 2])
	{
		cout << "YES" << endl;
		cout << a[0];
		for (int i = 1; i < n; i++)
			cout << "->" << a[i];
		cout << endl;
		return 0;
	}
	if (!a[n - 2])
	{
		bool flag = false;
		cout << "YES" << endl;
		int k = 1;
		if (!a[0])
		{
			flag = true;
			cout << "(" << a[0] << "->(" << a[1];
			k = 2;
		}
		else
			cout << a[0];
		for (int i = k; i < n - 1; i++)
		{
			cout << "->";
			if (!flag && !a[i])
			{
				flag = true;
				cout << "(" << a[i] << "->(";
				i++;
			}
			if (i < n - 1)
				cout << a[i];
		}
		cout << "))->" << a[n - 1] << endl;
		return 0;
	}
	return 0;
}