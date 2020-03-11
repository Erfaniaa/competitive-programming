/*
	SubmissionId	:	4033938
	ContestId	:	309
	Index	:	C
	ProblemName	:	Memory for Arrays
	ProblemTags	:	['binary search', 'bitmasks', 'greedy']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[1000 * 1000], b[1000 * 1000];
int bits[40];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		int x = a[i];
		int j = 0;
		while (x)
		{
			if (x % 2)
				bits[j]++;
			j++;
			x /= 2;	
		}
	}
	for (int i = 0; i < m; i++)
		cin >> b[i];	
	sort(b, b + m);
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		if (bits[b[i]] != 0)
		{
			bits[b[i]]--;
			ans++;
		}
		else
		{
			bool flag = false;
			for (int j = b[i] + 1; j < 40; j++)
				if (bits[j] > 0)
				{
					bits[j]--;
					for (int k = b[i]; k < j; k++)
						bits[k]++;
					bits[b[i]]++;
					flag = true;
					break;
				}
			if (flag)
			{
				bits[b[i]]--;
				ans++;
			}
			else
				break;
		}
	}
	cout << ans << endl;
}
