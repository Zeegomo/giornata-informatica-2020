#include <bits/stdc++.h>

using namespace std;

const int MN = 100005;

vector<int> g[MN];
int dist[MN];
int res[MN];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,u,v;
	cin>>n>>m;
    while(m--){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans=0;
    queue<int> q;
    dist[0]=1;
    q.push(0);
    while(!q.empty()){
        ++ans;
        u=q.front();
        q.pop();
        ++res[dist[u]];
        for(auto v:g[u]){
            if(!dist[v]){
                q.push(v);
                dist[v]=dist[u]+1;
            }
        }
    }
    cout<<ans<<' '<<dist[u]-1<<'\n';
    for(v=2; v<=dist[u]; ++v)
        cout<<res[v]<<' ';
    cout<<'\n';
	return 0;
}
