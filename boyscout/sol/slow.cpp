#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n+1);

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<bool> infected(n+1, false);
    vector<bool> toBeInfected(n+1, false);
    toBeInfected[0] = true;
    infected[0] = true;

    int T = 1;
    int D = 0;

    vector<int> infDays(n+1, 0);

    bool go;

    do {
        go = false;

        for(int i = 0; i <= n; i++) {
            if (infected[i]) {
                for (auto u : g[i]) {
                    if (!toBeInfected[u]) {
                        toBeInfected[u] = true;
                        go = true;
                        T++;
                        infDays[D]++;
                    }
                }
            }
        }

        for(int i = 0; i <= n; i++) {
            infected[i] = toBeInfected[i];
        }
    } while(go && ++D);

    cout << T << ' ' << D << endl;

    for(int i = 0; i < D; i++) {
        cout << infDays[i] << ' ';
    }

    cout << endl;

    return 0;
}