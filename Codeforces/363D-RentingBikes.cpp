/*
	SubmissionId	:	5067204
	ContestId	:	363
	Index	:	D
	ProblemName	:	Renting Bikes
	ProblemTags	:	['binary search', 'greedy']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>
#include<algorithm>

using namespace std;

#define ll long long
#define M 100010

ll n, m, a, money , b[M], p[M], sum;
int ans;

bool isGood(int k)
{
    bool ret = true;
    ll idx = k - 1;
    ll pool = a;
    sum = 0;
    for (int i = n - 1; i >= n - k; i--)
    {
        if (pool < 0)
            return false;
        if (b[i] < p[idx])
            pool -= p[idx] - b[i];
        idx--;
    }
    if (pool < 0)
        return false;
    return true;
}

void bs(int l, int r)
{
    int mid = (l + r) / 2;
    if (r - l <= 0)
        return;
    if (isGood(mid))
    {
        ans = max(ans, mid);
        bs(mid + 1, r);
    }
    else
        bs(l, mid);
}

int main()
{
    cin >> n >> m >> a;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++)
        cin >> p[i];
    sort(b, b + n);
    sort(p, p + m);
    bs(0, min(m, n) + 1);
    for (int i = 0; i < ans; i++)
        sum += p[i];
    cout << ans << " " << max(sum - a, (ll)0) << endl;
}