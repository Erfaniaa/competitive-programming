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

string s;

int main()
{
    getline(cin, s);
    s = "A" + s + "A";
    string ans = string(1000, '0');
    string x, y;
    FOR (a, 0, Size(s) - 2)
        if (isalpha(s[a]))
        {
            char c = s[a];
            s[a] = '9';
            FOR (i, 1, Size(s) - 2)
                if (!isalpha(s[i]))
                {
                    int j = i + 1;
                    while (!isalpha(s[j]))
                        j++;
                    j--;
                    x = string(1000 - (j - i + 1), '0');
                    y = s.substr(i, j - i + 1);
                    x = x + y;
                    if (x > ans)
                        ans = x;
                    i = j;
                }
            //debug(s);
            s[a] = c;
        }
    int i = 0;
    while (i < (Size(ans) - 1) && ans[i] == '0')
        i++;
    cout << ans.substr(i) << endl;
	return 0;
}
