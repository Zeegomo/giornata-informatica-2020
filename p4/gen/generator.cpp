#include <bits/stdc++.h>

using namespace std;

struct random_boy{
	 mt19937 rng;
	 uniform_int_distribution<int> gen;
	 random_boy() : rng(chrono::steady_clock::now().time_since_epoch().count()){}
	 random_boy(int seed) : rng(seed){}

	 int rand32() { return gen(rng);}
  
	 // return value in [l, r]
	 int rand_in(int l, int r){
	 // to avoid breaking things
	 if(l > r) swap(l, r);
		return rand32() % (r - l + 1) + l;
	 }
};

signed main(int argc, char** argv) {
	if(argc != 5)
	 	return 1;

	int n, q, b, seed;
	n = stoi(argv[1]);
	q = stoi(argv[2]);
	b = stoi(argv[3]);
	seed = stoi(argv[4]);
	random_boy randy = random_boy(seed);
	if(n == -1){
		cout <<"5 1 2 3 4 5 2 2 1 2 2 1 1 ";
		return 0;
	}

	if(n == -2){
		cout<<"5\n";
		cout<<"1 2 3 4 5\n";
		cout<<"2\n";
		cout<<"1 1 1 10\n";
		cout<<"2 1 2\n";
		return 0;
	}	
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		v[i] = randy.rand_in(1, 1e6);
	}
	cout << n << "\n";
	for(int i : v)
		cout<<i<<" ";
	cout<<"\n";
	cout<<q<<"\n";
	vector<vector<int>> queries;
	for(int i = 0; i < b; i++){
		queries.push_back({1, randy.rand_in(1, 1+i), randy.rand_in(1, n), randy.rand_in(1, 1e6)});
	}
	for(int i = 0; i < q-b; i++){
		queries.push_back({2, randy.rand_in(1, 1+b), randy.rand_in(1, 1e6)});
	}
	for(auto v : queries){
		for(int i : v)
			cout<<i<<" ";
		cout<<"\n";
	}
}
