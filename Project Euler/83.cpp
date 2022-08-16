#include <iostream>

using namespace std;

void dijkstra(int s)
{

}

int hash(int x, int y)
{
	return (x - 1) * n + y;
}

void addEgde(int a1, int a2, int b1, int b2)
{
	adj[hash(a1, a2)].push_back(hash(b1, b2));
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	return 0;
}