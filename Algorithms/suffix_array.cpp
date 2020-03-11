#include<cstdio>
#include<algorithm>

const int MAXN = 100010;
const int MAXLOGN = 18;

int idx[MAXN], p[MAXLOGN][MAXN], n, out[10];
char s[MAXN];

struct Tri
{
    int x, y, z;
    Tri(int _x = 0, int _y = 0, int _z = 0)
    {
        x = _x;
        y = _y;
        z = _z;
    }
} q[MAXN];

inline bool compare(const Tri &a, const Tri &b)
{
    if (a.x != b.x)
        return a.x < b.x;
    if (a.y != b.y)
        return a.y < b.y;
    return a.z < b.z;
}

inline void suffixArray()
{
    for (int i = 0; i < n; i++)
        p[0][i] = s[i];
    for (int i = 1; i < MAXLOGN; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int k = j + (1 << (i - 1));
            q[j] = Tri(p[i - 1][j], k < n ? p[i - 1][k] : -1, j);
        }
        std::sort(q, q + n, compare);
        p[i][q[0].z] = 0;
        for (int j = 1; j < n; j++)
            p[i][q[j].z] = ((q[j].x == q[j - 1].x && q[j].y == q[j - 1].y) ? p[i][q[j - 1].z] : j);
    }
}

int main()
{
    while (true)
    {
        s[n++] = getchar();
        if (s[n - 1] < '0' || s[n - 1] > 'z')
            break;
    }
    n--;
    suffixArray();
    for (int i = 0; i < n; i++)
        idx[p[MAXLOGN - 1][i]] = i;
    for (int i = 0; i < n; i++)
    {
        int sz = 0;
        do
        {
            out[sz++] = idx[i] % 10;
            idx[i] /= 10;
        }
        while (idx[i]);
        for (int j = 0; j < sz; j++)
            putchar(out[sz - 1 - j] + '0');
        putchar('\n');
    }
    return 0;
}
