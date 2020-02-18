    #include<bits/stdc++.h>
    #define ll long long
    #define pb push_back
    #define mp make_pair
    #define mt make_tuple
    #define s second
    #define f first
    #define mod 1000000007
    using namespace std;
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        ll t;
        cin>>t;
        while(t--)
        {
            string s;
            cin>>s;
            ll n=s.length();
            ll k=30;
            ll ar[60];
            memset(ar,-1,sizeof(ar));
            ar[30]=(int)s[0]-'a';
            ll f=0;
            ll cr[26];
            memset(cr,0,sizeof(cr));
            cr[(int)s[0]-'a']=1;
            for(ll i=1;i<n;i++)
            {
                ll p=(int)s[i]-'a';
                if(p==k)
                {
                    f=1;
                    break;
                }
                else 
                {
                    if(ar[k-1]==p)
                    k--;
                    else if(ar[k+1]==p)
                    k++;
                    else if(ar[k+1]==-1 and cr[p]==0)
                    {
                        ar[k+1]=p;
                        cr[p]=1;
                        k++;
                    }
                    else if(ar[k-1]==-1 and cr[p]==0)
                    {
                        ar[k-1]=p;
                        cr[p]=1;
                        k--;
                    }
                    else
                    {
                        f=1;
                        break;
                    }
                    //cout<<i<<" "<<k<<"\n";
                }
            }
            //cout<<f<<"\n";
            if(f==1)
            cout<<"NO"<<"\n";
            else
            {
                cout<<"YES"<<"\n";
            }
        }
        return 0;
    }