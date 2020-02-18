// sciroppo
// O(fast but wrong) solution using bfs
// builds an explicit graph and then uses bfs,
// but instead of shortest path in terms of weight
// it only finds shortest path in terms of number of edges.

#include <bits/stdc++.h>

using namespace std;

struct edge{
	pair<int, int> to;
	int weight;
};

int main() {
	// should pass without fast in :)
	// cin.tie(0), cin.sync_with_stdio(0);

	int n, m, r, c;
	cin >> n >> m >> r >> c;

	vector<vector<int>> d(n, vector<int>(m));
	for(auto &v : d)
		for(auto &i : v)
			cin >> i;

	// build graph
	vector<edge> g[n][m];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			// go down
			if(i + 1 < n) {
				// straight down
				g[i][j].push_back({
					{i+1, j},
					d[i+1][j]
				});
				// down left
				if(j - 1 >= 0) {
					g[i][j].push_back({
						{i+1, j-1},
						d[i+1][j-1]
					});
				}
				// down right
				if(j + 1 < m) {
					g[i][j].push_back({
						{i+1, j+1},
						d[i+1][j+1]
					});
				}
			}
			// horizontal movement
			else {
				// go left
				if(j - 1 >= 0) {
					g[i][j].push_back({
						{i, j-1},
						d[i][j-1]
					});
				}
				if(j + 1 < m) {
					g[i][j].push_back({
						{i, j+1},
						d[i][j+1]
					});
				}
			}
		}
	}

	// bfs
	const int INF = 2e9 + 5;

	vector<vector<int>> dist(n, vector<int>(m, INF));
	dist[r][c] = 0;

	queue<pair<int, int>> q;
	q.push({r, c});

	while(!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();
		// visit all neighbours
		for(edge &e : g[curr.first][curr.second]) {
			// if we never reached here before
			if(dist[e.to.first][e.to.second] == INF) {
				dist[e.to.first][e.to.second] = dist[curr.first][curr.second] + e.weight;
				q.push(e.to);
			}
		}
	}

	// find bottom cell which fills latest
	cout << *max_element(dist[n-1].begin(), dist[n-1].end());
}