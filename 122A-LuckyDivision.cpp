/*
	SubmissionId	:	5600888
	ContestId	:	122
	Index	:	A
	ProblemName	:	Lucky Division
	ProblemTags	:	['brute force', 'number theory']
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

bool isLucky(int a)
{
    int b = 1;
    while (a >= b)
    {
        int digit = (a / b) % 10;
        if (digit != 4 && digit != 7)
            return false;
        b *= 10;
    }
    return true;
}

int main()
{
    int n;
    bool b[1001] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (isLucky(i))
            for (int j = 1; j <= 1000 / i; j++)
                b[i * j] = true;
    }
    if (b[n])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}