#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> v(n);
	for(auto &i:v)cin>>i;
	cout<<(*max_element(v.begin(),v.end())-*min_element(v.begin(),v.end()))<<endl;
	return 0;
}
