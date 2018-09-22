/*
	SubmissionId	:	5600892
	ContestId	:	190
	Index	:	D
	ProblemName	:	Non-Secret Cypher
	ProblemTags	:	['two pointers']
	ProgrammingLanguage	:	GNU C++
	Verdict	:	OK
*/

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <stack>

using namespace std;

#define FOR(i, a, n) for (i = (a); i < n; i++)
#define FORINT(i, a, n) for (int i = (a); i < n; i++)
#define FORINTM(i, a, n) for (int i = (a); i < n; i++)
#define FORM(i, a, n) for (i = a; i >= n; i--)
#define Size(n) ((int)(n).size())
#define all(n) (n).begin(), (n).end()
#define ll long long
#define ull unsigned long long
#define pb push_back
#define VAL(x) #x << " = " << x;
#define Wln(x) cout << x << endl
#define W(x) cout << x
#define GetN(n); int n; cin >> n;
#define GetL(n); ll n; cin >> n;
#define GetStr(x); string x; getline(cin,x);
#define CinArray(array,a,n); for(int i = a;i < n ; i ++){ cin >> array[i] ; Max =max(Max,array[i]);}  
#define CoutArray(array,a,n); for(int i = a;i < n ; i ++) cout << array[i] << " ";
#define MapC map <char , int >
#define MapS map <string , int>
#define VecI vector <int>
#define VecS vector <string>
#define Pii pair<int , int >
#define Pll pair<ll , ll >

int main()
{
    long long n, a[400000], k, l = 0, r = 0, ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<long long, long long> b;
    b[a[0]] = 1;
    //cout << "OK!" << endl;
    while (l < n)
    {
        while (r < n && b[a[r]] < k)
        {
            r++;
            b[a[r]]++;
        }
        //cout << l << " " << r << " " << n - r << endl;
        ans += n - r;
        b[a[l]]--;
        l++;
        //r = l;
    }
    cout << ans << endl;
}