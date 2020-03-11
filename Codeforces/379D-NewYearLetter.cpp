/*
	SubmissionId	:	5585303
	ContestId	:	379
	Index	:	D
	ProblemName	:	New Year Letter
	ProblemTags	:	['bitmasks', 'brute force', 'dp']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<fstream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 100010

struct Tri
{
    char first, last;
    ll cnt;
    Tri(char _first = 'B', char _last = 'B', ll _cnt = 0)
    {
        first = _first;
        last = _last;
        cnt = _cnt;
    }
};

Tri d[1000];

ll f(int n)
{
    FOR (i, 3, n)
    {
        d[i].first = d[i - 2].first;
        d[i].last = d[i - 1].last;
        d[i].cnt = d[i - 1].cnt + d[i - 2].cnt;
        if (d[i - 2].last == 'A' && d[i - 1].first == 'C')
            d[i].cnt++;
        if (d[i].cnt > INF)
            return -1;
    }
    return d[n].cnt;
}

bool check(char first, char last, int cnt, int l)
{
    int tmp;
    if (l == 1)
        return (cnt == 0);
    if (l == 2)
    {
        if (first == 'A' && last == 'C')
            return (bool)(cnt == 1);
        else
            return (bool)(cnt == 0);
    }
    if (first == 'A')
        tmp = max(2 * cnt, 1);
    if (first == 'B')
        tmp = 2 * cnt + 1;
    if (first == 'C')
        tmp = 2 * cnt + 1;
    if (tmp < l)
        return true;
    if (tmp > l)
        return false;
    if (tmp == l && last == 'C')
        return true;
    if (tmp == l && last != 'C')
        return false;
}

void print(char first, char last, int cnt, int l)
{
    if (l == 1)
    {
        cout << first << endl;
        return;
    }
    if (first == 'A')
    {
        FOR (i, 1, cnt)
            cout << "AC";
        if (!cnt)
            cout << "A";
        int tmp = max(2 * cnt, 1);
        if (l != tmp)
        {
            FOR (i, 1, l - tmp - 1)
                cout << "B";
            cout << last << endl;
        }
        else
            cout << endl;
    }
    else
    {
        cout << first;
        FOR (i, 1, cnt)
            cout << "AC";
        if (l != 2 * cnt + 1)
        {
            FOR (i, 1, l - 2 * cnt - 2)
                cout << "B";
            cout << last << endl;
        }
        else
            cout << endl;
    }
}

int x, k, l1, l2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> x >> l1 >> l2;
    FOR (i, 0, l1)
    {
        FOR (c1, 'A', 'C')
        FOR (c2, 'A', 'C')
            if (check(c1, c2, i, l1))
                FOR (j, 0, l2)
                {
                    FOR (c3, 'A', 'C')
                    FOR (c4, 'A', 'C')
                    if (check(c3, c4, j, l2))
                    {
                        d[1] = Tri(c1, c2, i);
                        d[2] = Tri(c3, c4, j);
                        if (l1 == 1)
                            d[1].last = d[1].first;
                        if (l2 == 1)
                            d[2].last = d[2].first;
                        ll r = f(k);
                        if (r == x)
                        {
                            print(c1, c2, i, l1);
                            print(c3, c4, j, l2);
                            return 0;
                        }
                    }
                }
    }
    cout << "Happy new year!" << endl;
    return 0;
}