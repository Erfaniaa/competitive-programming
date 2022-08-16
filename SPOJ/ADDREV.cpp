#include <iostream>

using namespace std;

int reverse(int a)
{
    int x = 1;
    int z = 0;
    while (x <= a)
    {
        z = (10 * z) + ((a / x) % 10);
        x *= 10;
    }
    return z;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << reverse(reverse(a) + reverse(b)) << endl;
    }
}
