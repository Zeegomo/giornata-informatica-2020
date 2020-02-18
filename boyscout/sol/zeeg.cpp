#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
signed main() { 
	cin.tie(0);
	cin.sync_with_stdio();
	int n, m;
	cin>>n>>m;
	n++;
	vector<vector<int>> g(n);
	for(int i = 0; i < m; i++){
		int a, b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> dist(n, 1e9);
	queue<int> q;
	dist[0] = 0;
	q.push(0);
	while(!q.empty()){
		int t = q.front();q.pop();
		for(int e : g[t]){
			if(dist[e] > dist[t]+1){
				dist[e] = dist[t]+1;
				q.push(e);
			}
		}
	}

	int ma = 0;
	int cnt = 0;
	map<int, int> mm;
	for(int i = 0; i < n; i++){
		if(dist[i] != 1e9)
		ma = max(ma, dist[i]);
		if(dist[i] != 1e9)
			cnt++;
		mm[dist[i]]++;
	}

	cout << cnt << " " << ma << "\n";
	for(int i = 1; i <= ma; i++){
		cout << mm[i] << " ";
	}
}
