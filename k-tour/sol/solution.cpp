#include <bits/stdc++.h>

using namespace std;

#define INF 1e18
#define int long long

vector<int> dist(3e5, INF);

vector<int> dijkstra(int start, vector<vector<pair<int,int>>> &g){
    vector<int> ans;
    vector<int> vis;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()){
        auto f = pq.top(); pq.pop();

        if (f.first > dist[f.second]) continue;

        vis.push_back(f.second);

        if (f.second > start)
            ans.push_back(f.first);

        for(auto u : g[f.second]){
            if (f.first + u.second < dist[u.first]) {
                dist[u.first] = f.first + u.second;
                pq.push({dist[u.first], u.first});
            }
        }
    }

    for(int i : vis) {
        dist[i] = INF;
    }

    return ans;
}

signed main(){
    int n, m, k; cin >> n >> m >> k;

    vector<vector<pair<int,int>>> g(n);

    vector<pair<int, pair<int,int>>> edg;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        edg.push_back({c, {a, b}});
    }

    nth_element(edg.begin(), edg.begin() + min(m, k) - 1, edg.end());

    for(int i = 0; i < min(m, k); i++){
        int a = edg[i].second.first, b = edg[i].second.second, c = edg[i].first;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    vector<int> ans;

    for(int i = 0; i < n; i++){
        vector<int> roba = dijkstra(i, g);
        ans.insert(ans.end(), roba.begin(), roba.end());
    }

    nth_element(ans.begin(), ans.begin() + k - 1, ans.end());

    cout << ans[k-1] << endl;
}