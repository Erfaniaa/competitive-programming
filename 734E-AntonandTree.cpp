/*
	SubmissionId	:	22253311
	ContestId	:	734
	Index	:	E
	ProblemName	:	Anton and Tree
	ProblemTags	:	['dfs and similar', 'dp', 'trees']
	ProgrammingLanguage	:	GNU C++14
	Verdict	:	OK
*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 200010

vector<int> adj1[MAXN], adj2[MAXN];
int color[MAXN], compNum[MAXN], mark1[MAXN], mark2[MAXN], dis[MAXN];

void addEdge1(int x, int y)
{
	adj1[x].push_back(y);
	adj1[y].push_back(x);
}

void dfs1(int x, int comp)
{
	mark1[x] = 1;
	compNum[x] = comp;
	for (auto y: adj1[x])
		if (!mark1[y] && color[x] == color[y])
			dfs1(y, comp);
}

int dfs2(int x, int d)
{
	mark2[x] = true;
	dis[x] = d;
	for (auto y: adj2[x])
		if (!mark2[y])
			dfs2(y, d + 1);
}

int n, cnt;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> color[i];
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		addEdge1(x, y);
	}
	for (int i = 1; i <= n; i++)
		if (!mark1[i])
		{
			cnt++;
			dfs1(i, i);
		}
	for (int i = 1; i <= n; i++)
		for (auto j: adj1[i])
			if (compNum[i] != compNum[j])
				adj2[compNum[i]].push_back(compNum[j]);
	dfs2(1, 0);
	memset(mark2, 0, sizeof mark2);
	dfs2(max_element(dis + 1, dis + n + 1) - dis, 0);
	cout << (*max_element(dis + 1, dis + n + 1) + 1) / 2 << endl;
	return 0;
}