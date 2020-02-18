#include <bits/stdc++.h>

using namespace std;

struct S {
	int d, y, x;
};

int main() {
	int n, m, r, c; cin>>n>>m>>r>>c;
	vector<vector<int>> grid(n, vector<int>(m));
	for(auto &y : grid)
		for(auto &x : y)
			cin>>x;
	
	vector<vector<int>> dist(n, vector<int>(m, 1e9));
	queue<S> coda;
	coda.push({0, r, c});
	while(!coda.empty()) {
		auto s = coda.front(); coda.pop();
		int d = s.d, y = s.y, x = s.x;
		if (dist[y][x] > d) {
			dist[y][x] = d;
			if (y < n-1) {
				int ny = y+1;
				for(int k = -1; k <= 1; k++) {
					int nx = x + k;
					if (nx >= 0 && nx < m) {
						int nd = d + grid[ny][nx];
						if (nd < dist[ny][nx])
							coda.push({nd, ny, nx});
					}
				}
			}else {
				int ny = y;
				for(int k = -1; k <= 1; k+=2) {
					int nx = x + k;
					if (nx >= 0 && nx < m) {
						int nd = d + grid[ny][nx];
						if (nd < dist[ny][nx])
							coda.push({nd, ny, nx});
					}
				}
			}
		}
	}
	cout<<*max_element(dist.back().begin(), dist.back().end());
}
