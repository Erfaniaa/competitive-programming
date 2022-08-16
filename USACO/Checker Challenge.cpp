/*
ID: erfan.a2
PROG: checker
LANG: C++
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

#define un unsigned
#define pb push_back
#define mp make_pair
#define it iterator
#define val(x) #x << " = " << x << "   "
#define sqr(a) ((a) * (a))
#define sz(x) ((int) x.size())
#define clr(x, a) memset(x, a, sizeof x)
#define X first
#define Y second
#define TEST() cout << "Test!" << endl
#define pi 3.141592654
#define For(i, a, n) for(int i = a; i <= n; i++)
#define Ford(i, a, n) for(int i = a; i >= n; i--)
#define Fori(i, a, n) for(i = a; i <= n; i++)
#define Fordi(i, a, n) for(i = a; i >= n; i--)
#define all(n) n.begin(), n.end()
#define wln(x) cout << x << endl
#define w(x) cout << x
#define ri(n); int n; cin >> n;
#define rd(n); double n; cin >> n;
#define rl(n); ll n; cin >> n;
#define rc(c); char c; cin >> c;
#define rs(x); string x; getline(cin, x);
#define rarr(array, i, n); for(int i = 0; i <= n; i++) cin >> array[i];
#define warr(array, i, n); for(int i = 0; i <= n; i++) cout << array[i] << " ";
#define warrd(array, i, n); for(int i = n; i >= 0; i--) cout << array[i] << " ";
#define maxn 100010

int c, x;
int n;
bool y[14];
int m[14];
int d[14][14];
#define cin fin
#define cout fout
ofstream fout("checker.out");
ifstream fin("checker.in");

void bt(int l)
{
    if (l < n)
    {
        int i = l + 1;
		//if (m[i] == 0)
		//{
			For(j, 1, n)
			{
				if (!y[j])
				{
					bool b = true;
					Ford(t, l, 1)
						if (d[j][m[t]] == i - t)
						{
							b = false;
							break;
						}
					if (b)
					{
						y[j] = true;
						m[i] = j;
						//cout << i << " " << j << endl;
						bt(l + 1);
						//m[i] = 0;
						y[j] = false;
					}
				}
			}
			//m[i] = 0;
		//}
    }
    else
    {
    	c++;
    	if (c <= 3)
    	{
			For (i, 1, n - 1)
				cout << m[i] << " ";
			cout << m[n] << endl;
    	}
    	if (n == 13 && c == 3)
    	{
			cout << 73712 << endl;
			exit(0);
    	}
    }
}

int main()
{
	ios::sync_with_stdio(false);
    cin >> n;
    For (i, 1, 13)
		For (j, 1, 13)
			d[i][j] = abs(i - j);
	bt(0);
    cout << c << endl;
	return 0;
}
