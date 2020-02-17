// MyK_00L 2020-02-12 15:50
 
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
void solve(){
	string s;
	cin>>s;
	set<int> g[30];
	for(int i=0; i<s.size()-1; ++i){
		g[s[i]-'a'].insert(s[i+1]-'a');
		g[s[i+1]-'a'].insert(s[i]-'a');
	}
	int p;
	int n1=0,n2=0;
	for(int i=0; i<26; ++i){
		if(g[i].size()==1){
			n1++;
			p=i;
		} else if(g[i].size()==2){
			n2++;
		} else if(g[i].size()>2) {
			cout<<"NO\n";
			return;
		}
	}
	vector<bool> vis(26,0);
	if(n1==2){
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}