#include <bits/stdc++.h>

using namespace std;

int phi(int x)
{
    int ret = x;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            while (x % i == 0)
                x /= i;
            ret = ret / i * (i - 1);
        }
    }
    if (x > 1)
        ret = ret / x * (x - 1);
    return ret;
}

bool mark[1000010];
int p[1000010];

int main()
{
    mark[1] = true;
    for (int i = 2; i <= 1000000; i++)
        if (!mark[i])
            for (int j = 2 * i; j <= 1000000; j += i)
                mark[j] = true;
    for (int i = 1; i <= 1000000; i++)
        p[i] = i;
    for (int i = 2; i <= 1000000; i++)
        if (!mark[i])
            for (int j = i; j <= 1000000; j += i)
                p[j] = p[j] / i * (i - 1);
    for (int i = 1; i <= 30; i++)
        cout << i << ": " << p[i] << " " << phi(i) << endl;
    return 0;
}
