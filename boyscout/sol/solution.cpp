#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m;

    // adj list
    vector<vector<int>> g(n+1);

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // levels size
    vector<int> l(n+1, 0);
    // visited
    vector<bool> vis(n+1, false);

    // queue with level
    queue<pair<int,int>> q;
    q.push({0, 0});
    vis[0] = true;

    int D = 0;      // max level depth
    int T = 0;      // number of visited nodes

    while(!q.empty()){
        auto v = q.front();
        q.pop();

        T++;

        for(auto u : g[v.first]){
            if(!vis[u]) {
                vis[u] = true;
                int nextL = v.second + 1;
                l[nextL]++;
                q.push({u, nextL});
                D = nextL;
            }
        }
    }

    cout << T << ' ' << D << endl;

    for(int i = 1; i <= D; i++) {
        cout << l[i] << ' ';
    }

    cout << endl;


    return 0;
}