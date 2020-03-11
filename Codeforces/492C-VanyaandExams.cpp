/*
	SubmissionId	:	13395598
	ContestId	:	492
	Index	:	C
	ProblemName	:	Vanya and Exams
	ProblemTags	:	['greedy', 'sortings']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

int n, r;
long long sum, s, ans;
pair<int, int> a[100010];

int main()
{
	cin >> n >> r >> sum;
	sum *= n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].second >> a[i].first;
		s += a[i].second;
	}
	sort(a, a + n);
	int i = 0;
	while (i < n && s < sum)
	{
		ans += min((long long)r - a[i].second, sum - s) * a[i].first;
		s += min((long long)r - a[i].second, sum - s);
		i++;
	}
	cout << ans << endl;
	return 0;
}