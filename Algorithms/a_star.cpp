#include <bits/stdc++.h>

using namespace std;

fstream fin("a_star_map.in");

#define X first
#define Y second

const int INF = 1000000000 / 2;
const int MAXROWS = 1000;
const int MAXCOLS = 1000;
const int MAXNODES = MAXROWS * MAXCOLS + 10;
const int INVALID = -1;
const int DX[4] = {-1, +1, 0, 0};
const int DY[4] = {0, 0, -1, +1};
const char WALL = '1';
const char NOTWALL = '0';
const char PATH = '*';
const char START = 'P';
const char GOAL = 'G';

int rows, cols, cost[MAXNODES], dis[MAXNODES], par[MAXNODES];
char grid[MAXROWS][MAXCOLS];

int heuristic(pair<int, int> curXY, pair<int, int> goalXY) {
	return abs(curXY.X - goalXY.X) + abs(curXY.Y - goalXY.Y); //manhattan distance
}

pair<int, int> nodeIdToXY(int nodeId) {
	return make_pair(nodeId % cols, nodeId / cols);
}

int xyToNodeId(pair<int, int> nodeXY) {
	return nodeXY.Y * cols + nodeXY.X;
}

void aStar(int rows, int cols, pair<int, int> startXY, pair<int, int> goalXY) {
	set<pair<int, int> > st;
	for (int i = 0; i < rows * cols; i++) {
		cost[i] = INF;
		dis[i] = INF;
		par[i] = INVALID;
	}
	int startNodeId = xyToNodeId(startXY);
	st.insert(make_pair(0 + heuristic(startXY, goalXY), startNodeId));
	cost[startNodeId] = 0 + heuristic(startXY, goalXY);
	dis[startNodeId] = 0;
	while (!st.empty()) {
		int v = (*st.begin()).second;
		st.erase(st.begin());
		int x = nodeIdToXY(v).X;
		int y = nodeIdToXY(v).Y;
		int rnd = rand() & 3;
		for (int k = 0; k < 4; k++) {
			int x2 = x + DX[(rnd + k) & 3];
			int y2 = y + DY[(rnd + k) & 3];
			int u = xyToNodeId(make_pair(x2, y2));
			if (x2 < 0 || x2 >= cols || y2 < 0 || y2 >= rows)
				continue;
			if (grid[y2][x2] == WALL)
				continue;
			dis[u] = min(dis[v] + 1, dis[u]); 
			int nodeCost = cost[u];
			int nodeNewCost = dis[v] + 1 + heuristic(make_pair(x2, y2), goalXY);
			if (((rnd & 1) && (nodeNewCost == nodeCost)) || (nodeNewCost < nodeCost)) {
				st.erase(make_pair(nodeCost, u));
				st.insert(make_pair(nodeNewCost, u));
				cost[u] = nodeNewCost;
				par[u] = v;
			}
		}
	}
}

void printPath(int rows, int cols, pair<int, int> goalXY) {
	vector<pair<int, int> > path;
	int node = xyToNodeId(goalXY);
	if (par[node] == INVALID) {
		cout << endl << "No paths to the destination." << endl;
		return;
	}
	while (node != INVALID) {
		int x = nodeIdToXY(node).X;
		int y = nodeIdToXY(node).Y;
		if (grid[y][x] == NOTWALL)
			grid[y][x] = PATH;
		node = par[node];
	}
	cout << endl << "A path from the source to the destination:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			cout << grid[i][j];
		cout << endl;
	}
}

int main() {
	srand(time(NULL));
	fin >> rows >> cols;
	pair<int, int> st, en;
	cout << "Original map:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			fin >> grid[i][j];
			cout << grid[i][j];
			if (grid[i][j] == START)
				st = make_pair(j, i);
			if (grid[i][j] == GOAL)
				en = make_pair(j, i);
		}
		cout << endl;
	}
	aStar(rows, cols, st, en);
	printPath(rows, cols, en);
	return 0;
}