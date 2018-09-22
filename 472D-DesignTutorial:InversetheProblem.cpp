/*
	SubmissionId	:	17139762
	ContestId	:	472
	Index	:	D
	ProblemName	:	Design Tutorial: Inverse the Problem
	ProblemTags	:	['dfs and similar', 'dsu', 'shortest paths', 'trees']
	ProgrammingLanguage	:	GNU C++11
	Verdict	:	OK
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 2001;

int n, edgesCount, par[MAXN], sz[MAXN], mat1[MAXN][MAXN], mark[MAXN], components;
int mat2[MAXN][MAXN];
vector<pair<int, int> > adj[MAXN];

struct Edge
{
	int w, x, y;
	inline Edge(int _w = 0, int _x = 0, int _y = 0)
	{
		w = _w;
		x = _x;
		y = _y;
	}
	inline bool operator < (Edge _e)
	{
		if (w != _e.w)
			return w < _e.w;
		if (x != _e.x)
			return x < _e.x;
		return y < _e.y;
	}
} e[MAXN * MAXN];

inline int find(int x)
{
	if (par[x] == x)
		return x;
	return par[x] = find(par[x]);
}

inline void merge(Edge& edge)
{
	int x = find(edge.x);
	int y = find(edge.y);
	if (x == y)
		return;
	if (sz[x] > sz[y])
		swap(x, y);
	par[x] = y;
	sz[y] += sz[x];
	components--;
	adj[edge.x].push_back({edge.y, edge.w});
	adj[edge.y].push_back({edge.x, edge.w});
}

void dfs(int v, int st, int dis)
{
	mark[v] = true;
	mat2[st][v] = mat2[v][st] = dis;
	for (int i = 0; i < adj[v].size(); i++)
		if (!mark[adj[v][i].first])
			dfs(adj[v][i].first, st, dis + adj[v][i].second);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int w;
			scanf("%d", &w);
			mat1[i][j] = w;
			e[edgesCount++] = Edge(w, i, j);
		}
	sort(e, e + edgesCount);
	for (int i = 1; i <= n; i++)
	{
		par[i] = i;
		sz[i] = 1;
	}
	components = n;
	for (int i = 0; i < edgesCount; i++)
		merge(e[i]);
	if (components != 1)
	{
		printf("NO");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		memset(mark, 0, sizeof mark);
		dfs(i, i, 0);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (mat1[i][j] != mat2[i][j] || (i != j && !mat2[i][j]))
			{
				printf("NO");
				return 0;
			}
	printf("YES");
	return 0;
}