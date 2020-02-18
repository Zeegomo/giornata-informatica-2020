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
                    if (!infected[u]) {
                        infected[u] = true;
                        go = true;
                        T++;
                        infDays[D]++;
                    }
                }
            }
        }
    } while(go && ++D);

    cout << T << ' ' << D << endl;

    for(int i = 0; i < D; i++) {
        cout << infDays[i] << ' ';
    }

    cout << endl;

    return 0;
}