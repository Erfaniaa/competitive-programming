#include <iostream>

using namespace std;

int n, a[10000], d[10000];

int main()
{
	ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        d[i] = 1;
    }
    int ans = 1.;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i] > a[j])
            {
                d[i] = max(d[i], d[j] + 1);
                ans = max(ans, d[i]);
            }
    cout << ans << endl;
	return 0;
}
