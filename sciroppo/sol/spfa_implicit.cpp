// sciroppo
// O(fast) solution using spfa
// uses spfa gettings edges on the fly

#include <bits/stdc++.h>

using namespace std;

// global variables so that we can use them from the neighbours function
int n, m;
vector<vector<int>> d;

vector<pair<int, int>> neighbours(pair<int, int> from) {
	int i = from.first, j = from.second;
	vector<pair<int,int>> ans;
	if(i + 1 < n) {
		ans.push_back({i+1, j});
		if(j-1 >= 0) {
			ans.push_back({i+1, j-1});
		}
		if(j+1 < m) {
			ans.push_back({i+1, j+1});
		}
	} else {
		if(j-1 >= 0) {
			ans.push_back({i, j-1});
		}
		if(j+1 < m) {
			ans.push_back({i, j+1});
		}
	}
	return ans;
}

int main() {
	// should pass without fast in :)
	// cin.tie(0), cin.sync_with_stdio(0);

	int r, c;
	cin >> n >> m >> r >> c;

	// resize global vector
	d.resize(n, vector<int>(m));
	for(auto &v : d)
		for(auto &i : v)
			cin >> i;

	// spfa
	const int INF = 2e9 + 5;

	vector<vector<int>> dist(n, vector<int>(m, INF));
	dist[r][c] = 0;

	queue<pair<int, int>> q;
	q.push({r, c});

	while(!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();
		// visit all neighbours
		for(pair<int, int> p : neighbours(curr)) {
			int weight = d[p.first][p.second];
			// if we can improve distance
			if(dist[curr.first][curr.second] + weight < dist[p.first][p.second]) {
				dist[p.first][p.second] = dist[curr.first][curr.second] + weight;
				q.push(p);
			}
		}
	}

	// find bottom cell which fills latest
	cout << *max_element(dist[n-1].begin(), dist[n-1].end());
}