#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> v(n);
	for(auto &i:v)cin>>i;
    sort(v.begin(),v.end());
    int res=0;
    for(int i=0; i<n-1; ++i)res+=v[i+1]-v[i];
    cout<<res<<endl;
	return 0;
}
