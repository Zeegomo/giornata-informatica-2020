#include <bits/stdc++.h>

using namespace std;

const int MN = 100005;

vector<int> g[MN];
int dist[MN];
int res[MN];

void dfs(int u){
    for(auto v:g[u]){
        if( (!dist[v]) || dist[u]+1<dist[v]){
            dist[v] = dist[u]+1;
            dfs(v);
        }
    }
}

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
    int md=0;
    dist[0]=1;
    dfs(0);
    for(u=0; u<=n; ++u){
        if(dist[u])ans++;
        res[dist[u]]++;
        md=max(md,dist[u]);
    }
    cout<<ans<<' '<<md-1<<'\n';
    for(v=2; v<=md; ++v)
        cout<<res[v]<<' ';
    cout<<'\n';
	return 0;
}
