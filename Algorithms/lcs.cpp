#include <iostream>
using namespace std;
#define sz(x) ((int)(x).size())

int d[1000][1000];

int main()
{
	ios::sync_with_stdio(false);
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 1; i <= sz(s1); i++)
        for (int j = 1; j <= sz(s2); j++)
            if (s1[i - 1] == s2[j - 1])
                d[i][j] = max(d[i - 1][j - 1] + 1, d[i][j]);
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
    cout << d[sz(s1)][sz(s2)] << endl;
	return 0;
}
