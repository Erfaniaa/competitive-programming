/*
	SubmissionId	:	1892008
	ContestId	:	205
	Index	:	D
	ProblemName	:	Little Elephant and Cards
	ProblemTags	:	['binary search', 'brute force', 'sortings']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <iostream>
#include <map>

using namespace std;

map<long, long> f, b, x, y;
long n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        f[x[i]]++;
        if (x[i] != y[i])
            b[y[i]]++;
    }
    long long m = 100000000000000000;
    for (int i = 0; i < n; i++)
    {
        if (f[x[i]] >= n / 2.0 || f[y[i]] >= n / 2.0)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (f[x[i]] + b[x[i]] >= n / 2.0)
            if ((n / 2) + (n % 2) - f[x[i]] < m)
            {
                m = (n / 2) + (n % 2) - f[x[i]];
                //cout << x[i] << endl;
            }
        if (f[y[i]] + b[y[i]] >= n / 2.0)
            if ((n / 2) + (n % 2) - f[y[i]] < m)
            {
                m = (n / 2) + (n % 2) - f[y[i]];
                //cout << x[i] << endl;
            }
    }
    if (m == 100000000000000000)
        cout << -1 << endl;
    else
        cout << m << endl;
}
