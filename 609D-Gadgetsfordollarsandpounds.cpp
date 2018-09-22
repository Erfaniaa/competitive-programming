/*
	SubmissionId	:	14901361
	ContestId	:	609
	Index	:	D
	ProblemName	:	Gadgets for dollars and pounds
	ProblemTags	:	['binary search', 'two pointers']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 200010;

int n, m, s, k, money[2][MAXN], mn[2], minDay[2];
pair<int, int> gad[MAXN];
vector<int> v;

bool check(int idx, int s)
{
	mn[0] = mn[1] = 1000000010;
	for (int j = 0; j <= 1; j++)
		for (int i = 1; i <= idx; i++)
			mn[j] = min(mn[j], money[j][i]);
	vector<pair<int, int> > v;
	for (int i = 1; i <= m; i++)
		v.push_back(pair<int, int>(gad[i].first * mn[gad[i].second - 1], i));
	sort(v.begin(), v.end());
	int tot = -1 ;
	for (int i = 0; i < (int)v.size(); i++)
	{
		s -= v[i].first;
		if(s >= 0){
			tot = i ;
		}
		else 
			break ;
	}
	return tot >= k-1;
}

#define deb(x) cout << #x << " : " << x << endl

void print(int idx, int s)
{
	printf("%I64d\n" , idx);
	mn[0] = mn[1] = 1000000010;
	for (int j = 0; j <= 1; j++)
		for (int i = 1; i <= idx; i++)
		{
			if (mn[j] > money[j][i])
			{
				mn[j] = money[j][i];
				minDay[j] = i;
			}
		}

	vector<pair<int, int> > v;
	for (int i = 1; i <= m; i++)
		v.push_back(pair<int, int>(gad[i].first * mn[gad[i].second - 1], i));
	sort(v.begin(), v.end());
	for (int i = 0; i < k; i++)
		printf("%I64d %I64d\n"  , v[i].second , minDay[gad[v[i].second].second - 1]);
}

int search(int l, int r)
{
	int ret = 1231231231;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid, s))
		{
			ret = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	if (ret == 1231231231)
		return -1;
	if (check(ret, s))
		return ret;
	else
		return -1;
}
#undef int
int main()
{
#define int long long
	scanf("%I64d%I64d%I64d%I64d" , &n , &m , &k , &s);
	for (int i = 1; i <= n; i++)
		scanf("%I64d" , &money[0][i]);
	for (int i = 1; i <= n; i++)
		scanf("%I64d" , &money[1][i]);
	for (int i = 1; i <= m; i++)
		scanf("%I64d%I64d" ,&gad[i].second ,&gad[i].first);
	int tmp = search(1, n);
	if (tmp == -1)
		printf("-1\n");
	else
		print(tmp, s);
	fflush(stdout);
	return 0;
}