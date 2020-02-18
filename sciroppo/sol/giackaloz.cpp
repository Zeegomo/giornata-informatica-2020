#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

int main(){
    int n, m; cin >> n >> m;

    int r, c; cin >> r >> c;

    int mat[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
    vector<vector<int>> dist(n, vector<int>(m, INF));

    pq.push({0, {r, c}});
    dist[r][c] = 0;

    while(!pq.empty()) {
        auto front = pq.top();
        pq.pop();

        int d = front.first;
        int x = front.second.first;
        int y = front.second.second;

        if (d > dist[x][y])
            continue;

        // laterale
        if (x == n-1) {
            if (y > 0 && d + mat[x][y-1] < dist[x][y-1]) {
                dist[x][y-1] = d + mat[x][y-1];
                pq.push({dist[x][y-1], {x, y-1}});
            }

            if (y < m-1 && d + mat[x][y+1] < dist[x][y+1]) {
                dist[x][y+1] = d + mat[x][y+1];
                pq.push({dist[x][y+1], {x, y+1}});
            }
        } else {
            // down - left
            if (y > 0 && d + mat[x+1][y-1] < dist[x+1][y-1]) {
                dist[x+1][y-1] = d + mat[x+1][y-1];
                pq.push({dist[x+1][y-1], {x+1, y-1}});
            }
            // down
            if (d + mat[x+1][y] < dist[x+1][y]) {
                dist[x+1][y] = d + mat[x+1][y];
                pq.push({dist[x+1][y], {x+1, y}});
            }
            // down - right
            if (y < m-1 && d + mat[x+1][y+1] < dist[x+1][y+1]) {
                dist[x+1][y+1] = d + mat[x+1][y+1];
                pq.push({dist[x+1][y+1], {x+1, y+1}});
            }
        }
    }

    int res = 0;
    for(int i = 0; i < m; i++){
        res = max(res, dist[n-1][i]);
    }

    cout << res << endl;
}