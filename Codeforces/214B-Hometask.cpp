/*
	SubmissionId	:	13395243
	ContestId	:	214
	Index	:	B
	ProblemName	:	Hometask
	ProblemTags	:	['brute force', 'constructive algorithms', 'greedy', 'math']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int cnt[20], n;
long long sum;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long x;
		cin >> x;
		cnt[x]++;
		sum += x;
	}
	if (!cnt[0])
	{
		cout << -1 << endl;
		return 0;
	}
	if (!sum)
	{
		cout << 0 << endl;
		return 0;	
	}
	string mx = "";
	int mn = 100000;
	for (int b = 0; b < 3; b++)
	for (int c = 0; c < 3; c++)
	for (int e = 0; e < 3; e++)
	for (int f = 0; f < 3; f++)
	for (int h = 0; h < 3; h++)
	for (int i = 0; i < 3; i++)
	if (cnt[8] >= b)
	if (cnt[7] >= c)
	if (cnt[5] >= e)
	if (cnt[4] >= f)
	if (cnt[2] >= h)
	if (cnt[1] >= i)
	{
		long long sum2 = sum - (b * 8 + c * 7 + e * 5 + f * 4 + h * 2 + i);
		if (sum2 % 3 == 0)
			mn = min(mn, b + c + e + f + h + i);
	}
	for (int b = 0; b < 3; b++)
	for (int c = 0; c < 3; c++)
	for (int e = 0; e < 3; e++)
	for (int f = 0; f < 3; f++)
	for (int h = 0; h < 3; h++)
	for (int i = 0; i < 3; i++)
	if (cnt[8] >= b)
	if (cnt[7] >= c)
	if (cnt[5] >= e)
	if (cnt[4] >= f)
	if (cnt[2] >= h)
	if (cnt[1] >= i)
	{
		long long sum2 = sum - (b * 8 + c * 7 + e * 5 + f * 4 + h * 2 + i);
		if (b + c + e + f + h + i == mn && sum2 % 3 == 0)
		{
			cnt[8] -= b;
			cnt[7] -= c;
			cnt[5] -= e;
			cnt[4] -= f;
			cnt[2] -= h;
			cnt[1] -= i;
			n -= b + c + e + f + h + i;
			if (cnt[0] == n)
			{
				cout << 0 << endl;
				return 0;
			}
			for (int j = 9; j >= 0; j--)
				for (int k = 1; k <= cnt[j]; k++)
					cout << j;
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}