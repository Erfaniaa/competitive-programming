/*
	SubmissionId	:	22737832
	ContestId	:	742
	Index	:	B
	ProblemName	:	Arpa’s obvious problem and Mehrdad’s terrible solution
	ProblemTags	:	['math', 'number theory']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, x, a[1000010];
long long ans, cnt[1000010];

int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 0; i < n; i++)
	{
		ans += cnt[a[i] ^ x];
		if (x == 0)
			ans--;
	}
	ans /= 2;
	cout << ans << endl;
}