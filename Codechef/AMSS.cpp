#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll maxn = 6002;

ll c[maxn + 3][maxn + 3];
ll twenty[maxn + 3] = {1};

int main() {
    ios::sync_with_stdio(false);
    for(int i = 1 ; i < maxn; i++) {
        twenty[i] = (twenty[i-1]*25)%mod;
    }
    for(int i = 0 ;i < maxn ; i++) {
        c[i][0] = 1;
    }
    for(int n=1; n<maxn ; n++) {
        for(int k= 1 ;k <= n ; k++) {
            c[n][k] = (c[n-1][k-1] + c[n-1][k])%mod;
        }
    }
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        ll tot = 0;
        for(int i= 1 ;i <=n ;i++) {
            int rem = n - i;
            ll ans = (c[rem + i][i]*c[rem + i][i])%mod;
            ans *= twenty[i-1];
            ans %= mod;
            
            ans *= 26;
            ans %= mod;

            tot += ans;
            tot %= mod;
        }
        cout << tot << endl;
    }
    return 0;
}
