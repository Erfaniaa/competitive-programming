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

int t;

int main()
{
    cin >> t;
    FOR (tt, 1, t)
    {
        string s;
        cin >> s;
        /*bool flag = false;
        FOR (i, 0, Size(s) - 1)
            if (s[i] != '#')
            {
                flag = true;
                break;
            }
        if (!flag)
        {
            cout << 0 << endl;
            continue;
        }*/
        int len = 0;
        int pos = 0;
        int k = 0;
        int ans = 0;
        FOR (i, 0, Size(s) - 1)
            if (s[i] == '#')
                FOR (j, i + 1, Size(s) - 1)
                    if (s[j] == '#')
                    {
                        if (j - i - 1 > len)
                        {
                            len = j - i - 1;
                            pos = k;
                            ans++;
                        }
                        i = j - 1;
                        k++;
                        break;
                    }
        cout << ans << endl;
    }
	return 0;
}
