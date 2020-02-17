#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,ma,mi,t;
	cin>>n;
    cin>>ma;
    mi=ma;
    while(--n){
        cin>>t;
        if(t>ma)ma=t;
        if(t<mi)mi=t;
    }
    cout<<ma-mi<<endl;
	return 0;
}
