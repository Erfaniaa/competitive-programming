/*
	SubmissionId	:	3921716
	ContestId	:	16
	Index	:	D
	ProblemName	:	Logging
	ProblemTags	:	['implementation', 'strings']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

//
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<fstream>
#include<sstream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define Size(x) ((int)((x).size()))
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)

string s, h1, m1;
int h[10000], m[10000];
bool a[10000];

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    FOR (i, 1, n)
    {
        getline(cin, s);
        h1 = s.substr(1, 2);
        m1 = s.substr(4, 2);
        if (s[7] == 'a')
			a[i] = true;
		else
			a[i] = false;
        stringstream sh, sm;
        sh.flush();
        sm.flush();
        sh.clear();
        sm.clear();
        sh << h1;
        sm << m1;
        sh >> h[i];
        sm >> m[i];
        h[i] %= 12;
        if (!a[i])
			h[i] += 12;
    }
    int ans = 1;
    int k = 0;
    FOR (i, 1, n - 1)
    {
		int t1 = h[i] * 10000 + m[i];
		int t2 = h[i + 1] * 10000 + m[i + 1];
		if (t1 == t2)
			k++;
		else
			k = 0;
		if (k == 10)
		{
			k = 0;
			ans++;
			continue;
		}
		if (!(a[i]) && a[i + 1])
		{
			ans++;
			//debug(i);
			continue;
		}
		if (t1 > t2)
		{
			ans++;
			//debug(i);
		}
    }
    cout << ans << endl;
	return 0;
}
