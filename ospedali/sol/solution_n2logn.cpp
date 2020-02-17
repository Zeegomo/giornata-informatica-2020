#include <bits/stdc++.h>

using namespace std;

const int MN = 1000000;

int ufp[MN];
int ufs[MN];
int find(int a){
    return ufp[a]==a?a:ufp[a]=find(ufp[a]);
}
void unite(int a, int b){
    if(ufs[a]<ufs[b])swap(a,b);
    ufs[a]+=ufs[b];
    ufp[b]=a;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> v(n);
	for(auto &i:v)cin>>i;
    vector<pair<int,int> > e;
    for(int i=0; i<n; ++i){
        ufp[i]=i;
        ufs[i]=1;
        for(int j=i+1; j<n; ++j){
            e.push_back({i,j});
        }
    }
    int res=0;
    sort(e.begin(),e.end(),[&](pair<int,int> a, pair<int,int> b){return abs(v[a.first]-v[a.second])<abs(v[b.first]-v[b.second]);});
	for(auto &i:e){
        int x=find(i.first),y=find(i.second);
        if(x!=y){
            unite(x,y);
            res+=abs(v[i.first]-v[i.second]);
        }
    }
    cout<<res<<endl;
    return 0;
}
