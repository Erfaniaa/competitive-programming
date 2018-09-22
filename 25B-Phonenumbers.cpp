/*
	SubmissionId	:	4076179
	ContestId	:	25
	Index	:	B
	ProblemName	:	Phone numbers
	ProblemTags	:	['implementation']
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
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)

int main()
{
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n;
	int m = n - (n % 2);
	cin >> s;
	int i = 0;
	while (i <= m - 2 - 2)
	{
        cout << s[i] << s[i + 1] << "-";
        i += 2;
	}
	cout << s.substr(i) << endl;
	return 0;
}
