#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n;
	cin>>n;
	unordered_set<string> s;
	for(int i = 0; i < n; i++){
		string line = "";
		getline(cin, line);
		if(s.count(line)){
			cout<<"YES";
			return 0;
		}
		s.insert(line);
	}
	cout<<"NO";
}