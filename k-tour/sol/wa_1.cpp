    #include<bits/stdc++.h>
    typedef long long ll;
    #define pb push_back
    #define mp make_pair
    #define fi first
    #define se second
    using namespace std;
    ll n,m,k,ta,tb,tc,b[202020],i;
    vector<ll> v[202020],isi;
    vector<ll> w[202020];
    map<ll,map<ll,ll> > me;
    void djik()
    {
        priority_queue<pair<ll,pair<ll,ll> > > pq;
        ll heh=0,ii;
        for(ii=1;ii<=n;ii++)
            pq.push(mp(0,mp(ii,ii)));
        while(!pq.empty())
        {
            ll jar=-pq.top().fi;
            ll dr=pq.top().se.fi;
            ll u=pq.top().se.se;
            pq.pop();
            if(me[dr][u]==1)continue;
            me[dr][u]=1;
            if(dr<u)
            {
                heh++;
                if(heh==k)
                {
                    cout<<jar<<"\n";
                    exit(0);
                }
            }
            ll ii;
            for(ii=0;ii<v[u].size();ii++)
            {
                pq.push(mp(-jar-w[u][ii],mp(dr,v[u][ii])));
            }
        }
    }
    int main()
    {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        cin>>n>>m>>k;
        for(i=1;i<=m;i++)
        {
            cin>>ta>>tb>>tc;
            v[ta].pb(tb);
            v[tb].pb(ta);
            w[ta].pb(tc);
            w[tb].pb(tc);
        }
        djik();
        // hai();
        // sort(isi.begin(),isi.end());
        // cout<<isi[k*2-1]<<"\n";
    }