#include <bits/stdc++.h>
 
using namespace std;
#define pii pair<int, int>
#define F first
#define S second
#define INF 1e9 

const int maxn = 2e5+10;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n, x;
    cin>>t;
    while (t--) {
        cin>>n;
        int cycle = 0, dcycle = 0;
        vector<set<int>> adj(n+1);
        vector<int> degree(n+1);
        vector<bool> mark(n+1);
        for (int i=1; i<=n; i++) {
            cin>>x;
            adj[i].insert(x);
            adj[x].insert(i);
        }

        for (int i=1; i<=n; i++)
            degree[i] = adj[i].size();

        vector<int> comp;
        for (int i=1; i<=n; i++) {
            if (mark[i]) continue;

            comp.clear();
            stack<int> st;
            st.push(i);

            while (st.size()) {
                int v = st.top();
                comp.push_back(v);
                mark[v] = true;
                st.pop();

                for (auto u : adj[v]) 
                    if (!mark[u]) 
                        st.push(u);
                
            }
            bool has_cycle = true;
            for (auto v : comp) 
                if (degree[v] == 1) {
                    has_cycle = false;
                    break;
                }
                
            
            if (has_cycle) 
                cycle++;
            else 
                dcycle++;

        }


        int mn = cycle + min(dcycle, 1);
        int mx = cycle + dcycle;

        cout<<mn<<' '<<mx<<'\n';
    }
}