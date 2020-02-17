#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
vector<int> visited(100);
string dfs(vector<set<int>> &g, int i, int p){
    visited[i] = 1;
    char c = i+'a';
    string res(1, c);
    for(int e : g[i]){
    	if(e != p && !visited[e]){
    		res += dfs(g, e, i);
    	}
    }
	return res;
}

signed main() { 
    cin.tie(0);
    cin.sync_with_stdio();
    int t; 
    cin>>t;
    while(t--){
    	visited = vector<int>(100);
    	string s;
    	cin>>s;
    	vector<set<int>> g(26);
    	for(int i = 1; i < s.size(); i++){
    		g[s[i]-'a'].insert(s[i-1]-'a');
    		g[s[i-1]-'a'].insert(s[i]-'a');
    	}
    	bool f = true;
    	vector<int> start;
    	for(int i = 0; i < 26; i++){
    		if(g[i].size() > 2){
    			f = false;
    			continue;
    		}
    		if(g[i].size() < 2){
    			start.push_back(i);
    		}
    	}
    	if(!f){
    		cout<<"NO\n";
    		continue;
    	}
    	string sol = "";
    	for(int i : start){
    		if(!visited[i]){
    			sol += dfs(g, i, -1);
    		}
    	}
    	if(sol.size() == 26){
    		cout<<"YES\n";
    	}else{
    		cout<<"NO\n";
    	}
    	}
    }