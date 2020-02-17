#include <bits/stdc++.h>

using namespace std;


struct random_boy{
 	mt19937 rng;
	 uniform_int_distribution<long long int> gen;
	random_boy() : rng(chrono::steady_clock::now().time_since_epoch().count()){}
	random_boy(int seed) : rng(seed){}

	long long int rand32() { return gen(rng);}
  
	// return value in [l, r]
	long long int rand_in(long long int l, long long int r){
		// to avoid breaking things
		if(l > r) swap(l, r);
		return rand32() % (r - l + 1) + l;
  	}
};

int main(int argc, char** argv) {
	if(argc != 4)
		return 1;

  	int n = stoi(argv[1]);
	int m = stoi(argv[2]);
	int seed = stoi(argv[3]);
    	random_boy randy(seed);

	if (seed == -1) {
		cout << "5 5 2 2" << endl;
	       	cout << "..##." << "\n";
		cout << ".#..." << "\n";
	 	cout << ".####" << "\n";
		cout << "#####" << "\n";
		cout << "....." << "\n";
		cout << "#." << "\n";
		cout << ".#" << "\n";
	} else if (seed == -2){
		cout << "5 5 2 2" << endl;
	       	cout << "..##." << "\n";
		cout << ".#..." << "\n";
	 	cout << ".####" << "\n";
		cout << "#####" << "\n";
		cout << "....." << "\n";
		cout << ".#" << "\n";
		cout << "#." << "\n";
	} else if (seed == -3){
		cout << "5 5 3 3" << endl;
	       	cout << "..##." << "\n";
		cout << ".#..." << "\n";
	 	cout << ".####" << "\n";
		cout << "#####" << "\n";
		cout << "....." << "\n";
		cout << "..." << "\n";
		cout << "..." << "\n";
	} else {
    		int a, b;
		a = randy.rand_in(2, n);
		b = randy.rand_in(2, m);
		vector<vector<char>> v(n, vector<char>(m));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				v[i][j] = randy.rand_in(0, 1) ? '#' : '.';
			}
		} 
		
		vector<vector<char>> sign(a, vector<char>(b));
		for(int i = 0; i < a; i++){
			for(int j = 0; j < b; j++){
				sign[i][j] = randy.rand_in(0, 1) ? '#' : '.';
			}
		}

		int o = randy.rand_in(0, 100);
		int x = randy.rand_in(0, n-a);
		int y = randy.rand_in(0, m-b);
		if (o < 80) {
			for(int i = x; i < x+a; i++){
				for(int j = y; j < y+b; j++){
					v[i][j] = sign[i-x][j-y];			
				}
			}
		}
		
		cout << n << " " << m << " " << a << " " << b << "\n";
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << v[i][j];
			}
			cout << "\n";
		}
		if(randy.rand_in(0, 1)){
			int t, r;
			t = randy.rand_in(0, a-1);
			r = randy.rand_in(0, b-1);
			sign[t][r] = sign[t][r] == '.' ? '#' : '.';
		}
		for(int i = 0; i < a; i++){
			for(int j = 0; j < b; j++){
				cout << sign[i][j];
			}
			cout << "\n";
		}
	}
}
