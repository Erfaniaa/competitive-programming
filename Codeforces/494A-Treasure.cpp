/*
	SubmissionId	:	13411666
	ContestId	:	494
	Index	:	A
	ProblemName	:	Treasure
	ProblemTags	:	['greedy']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define pb push_back
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cout << #x << " = " << x << "\n"
#define INF (1000 * 1000 * 1000)
#define MAXN 10000

string s;
int x, y, last = -1;

vector<int> ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '#')
            last = i;
    if (last == -1)
    {
        cout << -1 << endl;
        return 0; 
    }
    for (int i = last + 1; i < s.length(); i++)
    {
        if (s[i] == '(')
            y++;
        if (s[i] == ')')
            y--;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            x++;
        if (s[i] == ')')
            x--;
        if (s[i] == '#')
        {   
            if (i < last)
            {
                if (x <= 0)
                {
                    cout << -1 << endl;
                    return 0;
                }
                x--;
            }
            else if (x + y <= 0)
            {
                cout << -1 << endl;
                return 0;
            }   
        }
    }
    x = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            x++;
        if (s[i] == ')')
            x--;
        if (s[i] == '#')
        {   
            if (i < last)
            {
                x--;
                ans.pb(1);
            }
            else
            {
                ans.pb(x + y);
                x -= x + y;
            }
        }
        //debug(x);
    }
    x = 0;
    int j = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            x++;
        if (s[i] == ')')
            x--;
        if (s[i] == '#')
        {
            x -= ans[j++];
            //cout << ans[j++] << endl;
        }
        if (x < 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}