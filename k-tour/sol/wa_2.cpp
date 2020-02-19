    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define ll long long
    #define node pair<ll, int> 
     
    const int N = 2e5 + 40;
    const int T = 1200;
     
    vector <pair<int, int>> a[N];
    vector <int> ways;
     
    int d[N], fl[2 * T][2 * T];
    int n, m, k;
     
    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cin >> n >> m >> k;
        vector < pair<int, pair<int, int>>> rbs;
        for (int i = 0; i < m; ++i)
        {
            int u, v, l;
            cin >> u >> v >> l;
            rbs.push_back({l, {u, v}});
        }
        sort(rbs.begin(), rbs.end());
        vector <int> nodes;
        map<pair<int, int>, int> lens;
        for (int i = 0; i < min(m, 2 * k); ++i)
        {
            ll l = rbs[i].first;
            int u = rbs[i].second.first;
            int v = rbs[i].second.second;
            lens[{u, v}] = lens[{v, u}] = l;
            nodes.push_back(u), nodes.push_back(v);
        }
        sort(nodes.begin(), nodes.end());
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
        int sz = nodes.size();
        for (int i = 0; i < sz; ++i) for (int j = 0; j < sz; ++j) fl[i][j] = 1e9 + 1;
        for (int i = 0; i < sz; ++i)
        {
            for (int j = 0; j < sz; ++j)
            {
                if (i == j)
                {
                    fl[i][j] = 0;
                }
                else
                {
                    if (!lens.count({nodes[i], nodes[j]})) fl[i][j] = 1e9 + 1;
                    else fl[i][j] = lens[{nodes[i], nodes[j]}];
                }
            }
        }
        for (int d = 0; d < sz; ++d)
        {
            for (int i = 0; i < sz; ++i)
            {
                for (int j = 0; j < sz; ++j)
                {
                    fl[i][j] = min(fl[i][j], fl[i][d] + fl[d][j]);
                }
            }
        }
        for (int i = 0; i < sz; ++i)
        {
            for (int j = i + 1; j < sz; ++j)
                ways.push_back(fl[i][j]);
        }
        sort(ways.begin(), ways.end());
        cout << ways[k - 1] << '\n';
        return 0;
    }