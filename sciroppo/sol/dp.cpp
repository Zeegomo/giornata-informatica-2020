// sciroppo
// O(fast) solution using dp
// not trivial to type because of the last layer,
// but let's do it in a cheaty way

#include <bits/stdc++.h>

using namespace std;


int main() {
	// should pass without fast in :)
	// cin.tie(0), cin.sync_with_stdio(0);

	int n, m, r, c;
	cin >> n >> m >> r >> c;

	// resize global vector
	vector<vector<int>> d(n, vector<int>(m));
	for(auto &v : d)
		for(auto &i : v)
			cin >> i;

	// dp top down
	const int INF = 2e9 + 5;
	vector<vector<int>> dist(n, vector<int>(m, INF));
	dist[r][c] = 0;
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < m; j++) {
			dist[i][j] = min(dist[i][j], d[i][j] + dist[i-1][j]);
			// if we can look left
			if(j - 1 >= 0) {
				dist[i][j] = min(dist[i][j], d[i][j] + dist[i-1][j-1]);
			}
			// if we can look right
			if(j + 1 < m) {
				dist[i][j] = min(dist[i][j], d[i][j] + dist[i-1][j+1]);
			}
		}
	}

	// look only left
	for(int i = 1; i < m; i++) {
		dist[n-1][i] = min(dist[n-1][i], dist[n-1][i-1] + d[n-1][i]);
	}
	// look only right
	for(int i = m - 2; i >= 0; i--) {
		dist[n-1][i] = min(dist[n-1][i], dist[n-1][i+1] + d[n-1][i]);
	}

	// find bottom cell which fills latest
	cout << *max_element(dist[n-1].begin(), dist[n-1].end());
}