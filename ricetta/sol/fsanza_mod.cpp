#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
    string s;
    cin >> s;
 
    vector<int> v;
    v.push_back(0);
    for(auto i : s)
        v.push_back(i-'a'+1);
    // v.push_back(0);
 
    vector<set<int>> g(30);
    vector<bool> used(26, false);
 
    for(int i=1; i<(int)v.size(); i++){
        if(g[v[i-1]].size() == 2 && g[v[i-1]].count(v[i]) == 0 || g[v[i]].size() == 2 && g[v[i]].count(v[i-1]) == 0){
            cout << "NO\n";
            return;
        }
        g[v[i]].insert(v[i-1]);
        g[v[i-1]].insert(v[i]);
    }
    cout << "YES\n";
}
 
int main(){
    int T;
    cin >> T;
 
    while(T--) solve();
}