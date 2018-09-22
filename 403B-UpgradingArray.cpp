/*
	SubmissionId	:	6042240
	ContestId	:	403
	Index	:	B
	ProblemName	:	Upgrading Array
	ProblemTags	:	['dp', 'greedy', 'number theory']
	ProgrammingLanguage	:	GNU C++0x
	Verdict	:	OK
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
const int MAX = 5005;
long long a[MAX];
unordered_map<int, bool> bad;
long long f(int val)
{
    long long ans = 0;
    int tmp = val;
    for (int i = 2; i * i <= tmp; i++)
        while (val % i == 0)
        {
            if (bad.count(i))
                ans--;
            else
                ans++;
            val /= i;
        }
    if (val != 1)
    {
        if (bad.count(val))
            ans--;
        else
            ans++;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        bad[val] = 1;
    }
    long long ans = 0, sum = 0;
    for (int i = 0; i < n; i++)
        sum += f(a[i]);
    ans = sum;
    for (long long i = n - 1; i >= 0; i--)
    {
        long long gcd = 0;
        for (int j = 0; j <= i; j++)
            gcd = __gcd(gcd, a[j]);
        long long x = f(gcd);
        if (x <= 0)
        {
            for (int j = 0; j <= i; j++)
                a[j] /= gcd;
            sum -= x * (i + 1);
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}