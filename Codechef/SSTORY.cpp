#include <cstdio>
#include <unordered_map>
#include <iostream>
using namespace std;

typedef long long ll;
#define X first
#define Y second
#define pb push_back
#define SQR(x) ((x) * (x))
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl
#define FOR(i, a, n) for(__typeof(n) i = (a); i <= (n); i++)
#define FORD(i, n, a) for(__typeof(n) i = (n); i >= (a); i--)
#define INF (1000 * 1000 * 1000)
#define MAXN 250010
#define BASE 701
#define MOD 1000000007

char s1[MAXN], s2[MAXN];
long long hash1[MAXN], hash2[MAXN], p[MAXN];
unordered_map<long long, int> mark;
int l1, l2, o;

inline long long segmentHash1(int l, int r)
{
	if (l == 0)
		return hash1[r];
	return hash1[r] - hash1[l - 1] * p[r - l + 1];
}

inline long long segmentHash2(int l, int r)
{
	if (l == 0)
		return hash2[r];
	return hash2[r] - hash2[l - 1] * p[r - l + 1];
}

inline void init()
{
	hash1[0] = s1[0];
	FOR (i, 1, l1 - 1)
		hash1[i] = BASE * hash1[i - 1] + s1[i];
	hash2[0] = s2[0];
	FOR (i, 1, l2 - 1)
		hash2[i] = BASE * hash2[i - 1] + s2[i];
	p[0] = 1;
	FOR (i, 1, MAXN - 1)
		p[i] = BASE * p[i - 1];
}

inline int check(int k, int l)
{
	mark.clear();
	FOR (i, o, l1 - k)
		mark[segmentHash1(i, i + k - 1)] = i;
	FOR (i, l, l2 - k)
		if (mark.count(segmentHash2(i, i + k - 1)))
			return i;
	return -1;
}

int main()
{
	char ch;
	while ((ch = getchar()) != '\n')
		s1[l1++] = ch;
	while ((ch = getchar()) != '\n')
		s2[l2++] = ch;
	s1[l1] = s2[l2] = 0;
	int tmp, l = 1, r = l2, len = 0, st, t = 0;
	init();
	while (l <= r)
	{
		int mid = (l + r) / 2;
		tmp = check(mid, t);
		if (tmp != -1)
		{
			l = mid + 1;
			t = tmp;
			if (mid > len)
			{
				st = tmp;
				len = mid;
			}
		}
		else
		{
			r = mid - 1;
			//t = 0;
		}
	}
	if (len == 0)
		printf("0\n");
	else
	{
		FOR (i, st, st + len - 1)
			putchar(s2[i]);
		printf("\n%d\n", len);
	}
	return 0;
}