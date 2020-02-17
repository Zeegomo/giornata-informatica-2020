#include <bits/stdc++.h>
using namespace std;


int check(vector<vector<char>> &v, vector<vector<char>> &vv, int x, int y){
	int c = 0;
	for(int i = x; i < x+vv.size(); i++){
		for(int j = y; j < y+vv[0].size(); j++){
			c += !(v[i][j] == vv[i-x][j-y]);
		}
	}
	return c;
}


int main() {
	int n, m, a, b;
	cin>>n>>m>>a>>b;
	vector<vector<char>> v(n, vector<char>(m));
	vector<vector<char>> vv(a, vector<char>(b));
	int mi = 1e9;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char a;
			cin>>a;
			v[i][j] = a;
		}
	}

	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			char a;
			cin>>a;
			vv[i][j] = a;
		}
	}
	for(int i = 0; i <= n-a; i++){
		for(int j = 0; j <= m-b; j++){
			mi = min(mi, check(v, vv, i, j));
		}
	}
	if(mi == 0){
		cout << "AUTENTICA";
	} else if (mi == 1) {
		cout << "FALSA";
	} else {
		cout << "DUBBIA";
	}
}
