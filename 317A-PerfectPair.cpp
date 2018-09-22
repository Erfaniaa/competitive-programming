/*
	SubmissionId	:	5601070
	ContestId	:	317
	Index	:	A
	ProblemName	:	Perfect Pair
	ProblemTags	:	['brute force']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

 #include<iostream>

using namespace std;

//1 -1000000000000000000 1000000000000000000
//0 1 1000000000000000000

int main()
{
    long long x, y, m;
    cin >> x >> y >> m;
    if (x >= m || y >= m)
    {
        cout << 0 << endl;
        return 0;
    }
    if (x <= 0 && y <= 0)
    {
        cout << -1 << endl;
        return 0;
    }
    if (x == 0 && y == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    if (y < x)
        swap(x, y);
    long long ans = 0;
    if (x < 0)
    {
        long long k = (-x) / y;
        x += k * y;
        ans += k;
        if (x < 0)
        {
            x += y;
            ans++;
        }
    }
    while (x < m && y < m)
    {
        if (x > y)
            y = x + y;
        else
            x = x + y;
        ans++;
        if (x >= m || y >= m)
            break;
    }
    cout << ans << endl;
    return 0;
}