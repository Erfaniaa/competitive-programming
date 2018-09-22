/*
	SubmissionId	:	18931094
	ContestId	:	689
	Index	:	A
	ProblemName	:	Mike and Cellphone
	ProblemTags	:	['brute force', 'constructive algorithms', 'implementation']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

pair<int, int> getPos(int num)
{
	if (!num)
		return {3, 1};
	num--;
	return {num / 3, num % 3};
}

bool isValid(pair<int, int> p)
{
	return ((p == pair<int, int>(3, 1)) || (p.X >= 0 && p.X <= 2 && p.Y >= 0 && p.Y <= 2));
}

int n, a[20];
pair<int, int> pos[20];

bool check(pair<int, int> offset)
{
	for (int i = 0; i < n; i++)
		if (!isValid({pos[i].X + offset.X, pos[i].Y + offset.Y}))
			return false;
	return true;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char ch;
		cin >> ch;
		a[i] = ch - '0';
	}
	pos[0] = {0, 0};
	for (int i = 1; i < n; i++)
	{
		pair<int, int> pos1 = getPos(a[i]);
		pair<int, int> pos2 = getPos(a[i - 1]);
		pos[i].X = pos[i - 1].X + pos1.X - pos2.X;
		pos[i].Y = pos[i - 1].Y + pos1.Y - pos2.Y;
	}
	int ans = 0;
	for (int i = 0; i < 10; i++)
		ans += check(getPos(i));
	if (ans == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}