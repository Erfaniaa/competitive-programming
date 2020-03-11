#include <bits/stdc++.h>

#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double dbl;
typedef float flt;
typedef string str;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T b; ss >> b; return b; }
template<class T> void print(T a, int p = -1) { if (p >= 0) cout << fixed << setprecision(p); cout << a; }
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
#define debug(x) cerr << #x << " = " << x << " (line: " << __LINE__ << ")" << endl
#define sqr(a) ((a) * (a))
#define sz(x) ((int) x.size())
#define ms(x, a) memset(x, a, sizeof x)
#define test() cerr << "Test!" << " (line: " << __LINE__ << ")" << endl
#define For(i, a, b) for(__typeof(b) i = (a); i <= (b); i++)
#define Ford(i, a, b) for(__typeof(a) i = (a); i >= (b); i--)
#define Fit(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define Fitd(i, v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); i--)
#define all(n) (n).begin(), (n).end()
#define wln(x) cout << x << endl
#define w(x) cout << x
#define r(x, type); type x; cin >> x;
#define rs(x); string x; cin.ignore(); getline(cin, x);
#define rarr(array, i, n); for(int i = 0; i <= n; i++) cin >> array[i];
#define warr(array, i, n); for(int i = 0; i <= n; i++) cout << array[i] << " ";
#define warrd(array, i, n); for(int i = n; i >= 0; i--) cout << array[i] << " ";
#define MAXSIZE 100000

template<class T>
struct MaxHeap
{
	T* a;
	int size;
	T error;
	MaxHeap(int maxSize)
	{
		clear();
		a = new T[maxSize];
		error = convert<int, T>(-inf);
	}
	~MaxHeap()
	{
		delete[] a;
	}
	int parent(int i)
	{
		if (i % 2 == 1)
			return i / 2;
		else
			return i / 2 - 1;
	}
	void heapify(int node)
	{
		int m = node;
		int left = 2 * node + 1;
		int right = 2 * node + 2;
		if (right <= size - 1 && a[right] > a[m])
			m = right;
		if (left <= size - 1 && a[left] > a[m])
			m = left;
		if (m != node)
		{
			swap(a[node], a[m]);
			heapify(m);
		}
	}
	//Change:
	void makeHeap(T *b, int length)
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
		while (i > 0 && a[i] > a[parent(i)])
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
	MaxHeap sort()
	{
		MaxHeap temp(size);
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
	T max()
	{
		if (!empty())
			return a[0];
		else
			//error
			return error;
	}
	T min()
	{
		if (!empty())
			return a[size - 1];
		else
			//error
			return error;
	}
	MaxHeap operator = (MaxHeap b)
	{
		size = b.size;
		For (i, 0, size - 1)
			a[i] = b.a[i];
		return b;
	}
	bool operator == (MaxHeap b)
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
		error = convert<int, T>(-inf);
	}
	~MinHeap()
	{
		delete[] a;
	}
	int parent(int i)
	{
		if (i % 2 == 1)
			return i / 2;
		else
			return i / 2 - 1;
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
	//Change:
	void makeHeap(T *b, int length)
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

int main()
{
	ios::sync_with_stdio(false);
	//Create a MinHeap or MaxHeap
	MinHeap<int> h(100);
	int n, x;
	cin >> n;
	int a[100];
	For (i, 0, n - 1)
		cin >> a[i];
	//Build heap
	h.makeHeap(a, n);
	For (i, 0, h.size - 1)
		cout << h[i] << " ";
	cout << endl;

	//Heapsort
	h.sort();
	For (i, 0, h.size - 1)
		cout << h[i] << " ";
	cout << endl;

	//Insert
	cin >> n;
	For (i, 0, n - 1)
	{
		cin >> x;
		h.insert(x);
	}
	For (i, 0, h.size - 1)
		cout << h[i] << " ";
	cout << endl;
	return 0;
}
