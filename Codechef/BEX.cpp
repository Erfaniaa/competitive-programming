#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <locale>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double dbl;
typedef float flt;
typedef string str;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T b; ss >> b; return b; }
template<class T> void print(T a, int p = -1) { if (p >= 0) cout << fixed << setprecision(p); cout << a; }
template<class T> bool isPrime(T a) { if (a == 1) return false; T n = (T)sqrt(a); for (T i = 2; i <= n; i++) if (a % i == 0) return false; return true; }
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dx[] = {-1, 0, +1, 0};
const int dy[] = {0, +1, 0, -1};
const int inf = (int)1e9 + 5;
const ll linf = (ll)1e16 + 5;
const double eps = 1e-9;
const double pi = 3.141592654;
#define vec vector
#define un unsigned
#define pb push_back
#define mp make_pair
#define IT iterator
#define X first
#define Y second
#define debug(x) cerr << #x << " = " << x << " #" << __LINE__ << '\n'
#define sqr(a) ((a) * (a))
#define sz(x) ((int)(x).size())
#define first(x) (*((x).begin()))
#define last(x) (*((x).end() - 1))
#define ms(x, a) memset(x, a, sizeof x)
#define test() cerr << "Test!" << " #" << __LINE__ << '\n'
#define For(i, a, b) for(typeof(b) i = (a); i <= (b); i++)
#define Ford(i, a, b) for(typeof(a) i = (a); i >= (b); i--)
#define Fit(i, v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define Fitd(i, v) for(typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); i--)
#define all(n) (n).begin(), (n).end()
#define wln(x) cout << x << '\n'
#define w(x) cout << x
#define r(x, type); type x; cin >> x;
#define rs(x); string x; getline(cin, x);
#define rarr(array, i, a, n); for(int i = a; i <= n; i++) cin >> array[i];
#define warr(array, i, a, n); for(int i = a; i <= n; i++) cout << array[i] << " ";
#define warrd(array, i, a, n); for(int i = n; i >= a; i--) cout << array[i] << " ";
#define maxn 100010

template<class T>
struct MinHeap
{
	T* a;
	int size;
	T error;
	MinHeap(int maxSize)
	{
		clear();
		a = new T[maxSize];
		//error = convert<int, T>(-inf);
	}
	~MinHeap()
	{
		delete[] a;
	}
	int parent(int i)
	{
		return (i - 1) / 2;
	}
	void heapify(int node)
	{
		int m = node;
		int left = 2 * node + 1;
		int right = 2 * node + 2;
		if (right <= size - 1 && a[right] < a[m])
			m = right;
		if (left <= size - 1 && a[left] < a[m])
			m = left;
		if (m != node)
		{
			swap(a[node], a[m]);
			heapify(m);
		}
	}
	void makeHeap(T b[], int length)
	{
		if (length > 0)
		{
			size = length;
			For (i, 0, length - 1)
				a[i] = b[i];
			Ford (i, parent(size - 1), 0)
				heapify(i);
		}
	}
	int insert(T x)
	{
		size++;
		a[size - 1] = x;
		int i = size - 1;
		while (i > 0 && a[i] < a[parent(i)])
		{
			swap(a[i], a[parent(i)]);
			i = parent(i);
		}
	}
	int find(T x)
	{
		For (i, 0, size - 1)
			if (a[i] == x)
				return i;
		//not found
		return -1;
	}
	T pop()
	{
		if (size > 0)
		{
			T top = a[0];
			a[0] = a[size - 1];
			size--;
			if (size > 0)
				heapify(0);
			return top;
		}
		//error
		return error;
	}
	MinHeap sort()
	{
		MinHeap temp(size);
		temp.size = size;
		int i = 0;
		while (!empty())
			temp.a[i++] = pop();
		size = temp.size;
		For (i, 0, size - 1)
			a[i] = temp.a[i];
		return temp;
	}
	bool empty()
	{
		return (size <= 0);
	}
	void clear()
	{
		size = 0;
	}
	T min()
	{
		if (!empty())
			return a[0];
		else
			//error
			return error;
	}
	T max()
	{
		if (!empty())
			return a[size - 1];
		else
			//error
			return error;
	}
	MinHeap operator = (MinHeap b)
	{
		size = b.size;
		For (i, 0, size - 1)
			a[i] = b.a[i];
		return b;
	}
	bool operator == (MinHeap b)
	{
		if (size != b.size)
			return false;
		For (i, 0, size - 1)
			if (a[i] != b.a[i])
				return false;
		return true;
	}
	T operator [] (int i)
	{
		if (i >= 0 && i < size)
			return a[i];
		else
			//error
			return error;
	}
};

#define pis pair<int,string>

MinHeap<pis> heap(1000 * 1000 + 1);
int n, a;
string s, s2;
vector<pis> v;


locale loc;
const collate<char>& coll = use_facet<collate<char> >(loc);
ll hash(string s)
{
	return coll.hash(s.data(), s.data() + s.length());
}

//map<pis, unsigned short int> mark, mark0;
map<ll, unsigned short int> mark[100 * 1000 + 1];

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(NULL);
	cin >> n;
	For (i, 1, n)
	{
		cin >> a;
		if (a == -1)
		{
			/*Ford (i, sz(v) - 1, 0)
				cerr << i << ": " << v[i].X << " " << v[i].Y << endl;
			cout << endl;*/
			pis book = heap.min();
			debug(book.X);
			debug(book.Y);
			int ans = -1;
			//mark.clear();
			//mark = mark0;
			Ford (i, sz(v) - 1, 0)
			{
				//mark[v[i]]++;
				debug(hash(v[i].Y));
				mark[hash(v[i].Y)][v[i].X]++;
				//debug(mark[v[i]]);
				if (v[i].X == book.X)
				{
					ans = sz(v) - 1 - i;
					s2 = v[i].Y;
					break;
				}
			}
			debug(ans);
			v.erase(v.begin() + (sz(v) - 1 - ans), v.end());
			For (i, 0, heap.size - 1)
			{
				if (/*mark[heap[i]] > 0*/mark[hash(heap[i].Y)][heap[i].X] > 0)
				{
					//if (heap.a[i].Y == "bye")
					//	debug(heap.a[i].X);
					heap.a[i].X = inf;
					heap.heapify(i);
					mark[hash(heap[i].Y)][heap[i].X]--;
					//mark[heap[i]]--;
				}
			}
			//if (heap.size >= 1)
				//heap.heapify(0);
			For (i, 0, heap.size - 1)
			{
				debug(heap[i].X);
				debug(heap[i].Y);
			}
			while (heap.size >= 1 && heap[heap.size - 1].X == inf)
				heap.size--;
			cout << ans << " " << s2 << endl;
			//debug(sz(v));
			/*if (sz(v))
			{
				Ford (i, sz(v) - 1, 0)
					cerr << i << "* " << v[i].X << " " << v[i].Y << endl;
				cout << endl;
			}*/
		}
		else
		{
			cin >> s;
			if (a != 0)
			{
				heap.insert(mp(a, s));
				v.pb(mp(a, s));
			}
		}
	}
	return 0;
}

/*

100
3 bye
2 bye
3 salam
2 salam
1 salam

*/
