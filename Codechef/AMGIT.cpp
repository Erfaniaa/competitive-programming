#include <bits/stdc++.h>

using namespace std;

int mem[2][20002];

struct Node {
    int state;
    map<string, int> children;
};

Node nodes[20002];

void doit(int now, int& nextNode, const string& dir, int ptr, int lastState) {
    int sz = 0;
    for(int i = ptr + 1 ; i < (int)dir.size() ; i++) {
        if(dir[i] == '/') {
            break;
        }
        sz ++;
    }
    int newPtr = ptr + sz + 1;
    string thisPart = dir.substr(ptr+1, sz);
    int next= nodes[now].children[thisPart];
    if(next == 0) {
        next = nextNode;
        nodes[now].children[thisPart] = next;
        nextNode++;
    }
    if(newPtr < (int)dir.size()) {
        doit(next, nextNode, dir, newPtr, lastState);
    } else {
        nodes[next].state = lastState;
    }
}

int dp(int isStaged, int on) {
    int& ref = mem[isStaged][on];

    if(ref != -1) {
        return ref;
    }
    
    if(nodes[on].children.empty()) {
        if(isStaged == nodes[on].state) {
            ref = 0;
        } else {
            ref = 1;
        }
    } else {
        ref = 123123123;
        int ans[2] = {0};
        for(auto& child: nodes[on].children) {
            ans[0] += dp(0, child.second);
            ans[1] += dp(1, child.second);
        }
        ans[1-isStaged] ++;
        ref = min(ans[0], ans[1]);
    }
    
    //cout << isStaged << " : " << on << " : " << ref << endl;

    return ref;
}

void dfs(int on, const string& tab, const string& me, int ind) {
    cout << tab << " " << ind << " : " << me << endl;
    cout << tab << "stage: " << nodes[ind].state << endl;
    for(auto& it: nodes[on].children) {
        dfs(it.second, tab + "\t", it.first, it.second);
    }
}

int main() {
    int c;
    cin >> c;
    while(c--) {
        memset(mem, -1, sizeof mem);
        for(int i = 0 ; i <20002; i++) {
            nodes[i].children.clear();
            nodes[i].state = 0;
        }
        int now = 2;
        int n;
        cin >> n;
        for(int i = 0 ;i < n ;i++) {
            string which, dir;
            cin >> which >> dir;
            int state = which[0] == 's';
            doit(1, now, dir, 0, state);
        }
//        dfs(1, "", "", 1);
//        cout << endl; 
        cout << dp(0, 1) << endl;
    }
    return 0;
}
