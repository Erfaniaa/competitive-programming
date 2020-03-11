/*
	SubmissionId	:	3978375
	ContestId	:	322
	Index	:	C
	ProblemName	:	Ciel and Robot
	ProblemTags	:	['implementation', 'math', 'number theory']
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

pii changePos(char c, pii vec)
{
    if (c == 'U')
        vec.Y++;
    if (c == 'D')
        vec.Y--;
    if (c == 'L')
        vec.X--;
    if (c == 'R')
        vec.X++;
    return vec;
}

int main()
{
    pii f;
    string s;
    cin >> f.X >> f.Y;
    cin >> s;
    if (f == mp(0, 0))
    {
        cout << "Yes" << endl;
        return 0;
    }
    pii vec = mp(0, 0), vec2 = mp(0, 0), vec3;
    FOR (i, 0, SZ(s) - 1)
        vec = changePos(s[i], vec);
    s = "0" + s;
    bool ans = false;
    if (vec == mp(0, 0))
    {
        FOR (i, 0, SZ(s) - 1)
        {
            vec2 = changePos(s[i], vec2);
            vec3 = mp(f.X - vec2.X, f.Y - vec2.Y);
            if (vec3 == mp(0, 0))
                ans = true;
        }
    }
    else if (vec.X == 0)
    {
        FOR (i, 0, SZ(s) - 1)
        {
            vec2 = changePos(s[i], vec2);
            vec3 = mp(f.X - vec2.X, f.Y - vec2.Y);
            if ((vec3.X == 0) && (vec3.Y % vec.Y == 0))
                if (vec3.Y / vec.Y >= 0)
                {
                    ans = true;
                    //debug(vec3.Y / vec.Y);
                    //debug(i);
                }
        }
    }
    else if (vec.Y == 0)
        FOR (i, 0, SZ(s) - 1)
        {
            vec2 = changePos(s[i], vec2);
            vec3 = mp(f.X - vec2.X, f.Y - vec2.Y);
            if ((vec3.Y == 0) && (vec3.X % vec.X == 0))
                if (vec3.X / vec.X >= 0)
                {
                    ans = true;
                    //debug(vec3.X / vec.X);
                    //debug(i);
                }
        }
    else if (vec.X != 0 && vec.Y != 0)
        FOR (i, 0, SZ(s) - 1)
        {
            vec2 = changePos(s[i], vec2);
            vec3 = mp(f.X - vec2.X, f.Y - vec2.Y);
            if ((vec3.X % vec.X == 0) && (vec3.Y % vec.Y == 0))
                if (vec3.X / vec.X == vec3.Y / vec.Y)
                    if (vec3.X / vec.X >= 0)
                    {
                        ans = true;
                        //debug(vec3.X / vec.X);
                        //debug(i);
                    }
        }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
	return 0;
}
