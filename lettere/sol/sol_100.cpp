#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
vector<vector<int>> nmhash(1e3, vector<int>(1e3));
vector<vector<int>> abhash(1e3, vector<int>(1e3));
const long long p = 31;
const long long q = 37;

ll binpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b%2){
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
void hashify(vector<vector<char>> &v, vector<vector<int>> &hhash){
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v[0].size(); j++){
			hhash[i][j] = ((v[i][j] * binpow(p, i)) % MOD * binpow(q, j)) % MOD;
		}
	}

	for(int i = 0; i < v.size(); i++){
		for(int j = 1; j < v[0].size(); j++){
			hhash[i][j] = (hhash[i][j] + hhash[i][j-1]) % MOD;
		}
	}
	for(int i = 1; i < v.size(); i++){
		for(int j = 0; j < v[0].size(); j++){
			hhash[i][j] = (hhash[i][j] + hhash[i-1][j]) % MOD;
		}
	}
}


ll inv(ll a){
	return binpow(a, MOD-2);
}
//x, y lower right corner
int get_hash(vector<vector<int>> &hhash, int a, int b, int x, int y){
	ll tmp = hhash[x][y];
	if(a > 0)
		tmp -= hhash[a-1][y];
	if(b > 0)
		tmp -= hhash[x][b-1];
	if(b > 0 && a > 0)
		tmp += hhash[a-1][b-1];
	tmp = ((tmp) % MOD + MOD) % MOD;
	return (((tmp * inv(binpow(p, a))) % MOD) * inv(binpow(q, b))) % MOD;
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
	hashify(v, nmhash);
	hashify(vv, abhash);
	int good = get_hash(abhash, 0, 0, a-1, b-1);
	set<int> s;
	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			ll old = vv[i][j];
			ll one = (old == '.' ? '#' : '.');
			old = (((old*binpow(q, j)) % MOD) * binpow(p, i)) % MOD;
			one = (((one*binpow(q, j)) % MOD) * binpow(p, i)) % MOD;
			ll ne = ((good - old + one) % MOD + MOD) % MOD;
			s.insert(ne);
		}
	}
	bool fake = 0;
	for(int i = 0; i <= n-a; i++){
		for(int j = 0; j <= m-b; j++){
			ll ho = get_hash(nmhash, i, j, i+a-1, j+b-1);
			if(ho == good){
				cout<<"AUTENTICA";
				return 0;
			} else if(s.count(ho)){
				fake = 1;
			}
		}
	}
	if (fake) {
		cout << "FALSA";
	} else {
		cout << "DUBBIA";
	}
}
