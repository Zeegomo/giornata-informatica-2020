    #include <bits/stdc++.h>
    using namespace std; 
    using ll = long long;
    #define int ll
    signed main() { 
        cin.tie(0);
        cin.sync_with_stdio();
        int n, m, k; 
        cin>>n>>m>>k;
        priority_queue<pair<ll, pair<pair<int, int>, set<int>>>, vector<pair<ll, pair<pair<int, int>, set<int>>>>, greater<pair<ll, pair<pair<int, int>, set<int>>>>> q;
        vector<vector<pair<int, ll>>> g(n);
        vector<pair<ll, pair<pair<int, int>, set<int>>>> v;
        for(int i = 0; i < m; i++){
            int x, y, w;
            cin>>x>>y>>w;
            x--;y--;
            g[x].push_back({y, w});
            g[y].push_back({x, w});
            v.push_back({w, {{x, y}, {x, y}}});
            v.push_back({w, {{y, x}, {y, x}}});
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < min(int(v.size()), 2*k+6); i++){
            q.push(v[i]);
        }
        ll up_bound = v.size() > 2*k+10 ? v[2*k+9].first : 1e15;
        set<pair<int, int>> vv;
        while(!q.empty()){
            auto u = q.top();q.pop();
            /*if(vv.count(u.second.first)){
                continue;   
            }*/
            bool b = false;
            if(u.second.first.first == u.second.first.second || vv.count(u.second.first))
                continue;
            if(u.second.first.first != u.second.first.second)
            if(!vv.count(u.second.first) && !vv.count({u.second.first.second, u.second.first.first})){
                k--;
                b =true;
                //cout << u.first << " " << u.second.first.first << "->" << u.second.first.second << "\n";
                if(k == 0){
                    cout << u.first;
                    return 0;
                }
            }else if(vv.count({u.second.first.second, u.second.first.first})){
                b = true;
                //cout << u.first << " " << u.second.first.first << "->" << u.second.first.second << "\n";
            }
            vv.insert(u.second.first);
            if(b)
            for(auto e : g[u.second.first.second]){
                if(e.second+u.first < up_bound){
                    set<int> s = u.second.second;
                    //if(b)
                    //cout << " ->" << e.second << endl;
                    q.push({e.second+u.first, {{u.second.first.first, e.first}, s}});
                }
            }
            //if(b)
            //cout<<endl;
        }
    }