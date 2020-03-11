#include <bits/stdc++.h>

using namespace std;

int t, n;

string cntStr(int cnt, string s)
{
    string ret = "";
    for (int i = 0; i < cnt; i++)
        ret += s;
    return ret;
}

int main()
{
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        cin >> n;
        map<string, int> cnt;
        for (int i = 1; i <= n; i++)
        {
            string s;
            cin >> s;
            cnt[s]++;
        }
        string ans = cntStr(cnt["aa"] / 2, "aa");
        ans += cntStr(min(cnt["ab"], cnt["ba"]), "ab");
        ans += cntStr(cnt["bb"] / 2, "bb");
        if (cnt["aa"] % 2 == 1)
        {
            ans += "a";
        }
        else
        {
            if (cnt["bb"] % 2 == 1)
                ans += "b";
        }
        cout << ans;
        for (int i = ans.length() - 1; i >= 0; i--)
            cout << ans[i];
        cout << endl;
    }
    return 0;
}